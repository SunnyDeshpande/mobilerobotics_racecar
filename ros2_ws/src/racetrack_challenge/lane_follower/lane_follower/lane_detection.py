#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from std_msgs.msg import Float64
from geometry_msgs.msg import Point

import numpy as np
import cv2
from cv_bridge import CvBridge


class LaneDetector(Node):
    def __init__(self):
        super().__init__('lane_detection')
        self.get_logger().info('Lane detection node started')
        self.lane_threshold_val = 150 # 90 if nice and bright (project), 60 if shady (project2_sunny), 150 if indoors bright (indoors)
        self.bridge = CvBridge()

        # Subscribe to the ZED left color rectified image
        self.create_subscription(
            Image,
            '/zed/zed_node/rgb/image_rect_color', #rgb for all bags but project2_sunny
            self.image_callback,
            10
        )

        # Numeric publishers
        self.lane_center_pub     = self.create_publisher(Float64, '/detect/lane',                 10)
        self.left_mid_pub        = self.create_publisher(Point,   '/detect/lane_left_midpoint',  10)
        self.right_mid_pub       = self.create_publisher(Point,   '/detect/lane_right_midpoint', 10)
        self.region_centroid_pub = self.create_publisher(Point,   '/detect/lane_region_centroid',10)

        # Image publishers
        self.mask_pub    = self.create_publisher(Image, '/camera/mask_lane_detected', 10)
        self.overlay_pub = self.create_publisher(Image, '/camera/centroid_overlay',   10)

        # Remember last fit if polyfit fails
        self.left_fit_prev  = None
        self.right_fit_prev = None

    def image_callback(self, msg: Image):
        # 1) Convert ROS Image → OpenCV BGR
        img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        H, W = img.shape[:2]

        # 2) Define bottom half ROI
        bot_y = 2*H // 3
        roi    = img[bot_y:, :]           # shape = (H/2, W, 3)

        # 2a) Denoise the ROI (colored)
        roi = cv2.fastNlMeansDenoisingColored(
        roi,      # input
        None,     # output; let the function allocate
        h=1,     # filter strength for luminance
        hColor=1,# filter strength for color components
        templateWindowSize=7,
        searchWindowSize=21
    )

        # 3) Threshold ROI to get binary mask of white lanes
        gray = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
        gray = cv2.medianBlur(gray, 9)
        _, mask_gray = cv2.threshold(gray, self.lane_threshold_val, 255, cv2.THRESH_BINARY) 

        hls = cv2.cvtColor(roi, cv2.COLOR_BGR2HLS)
        lower_white = np.array([0, 60,  0], dtype=np.uint8)
        upper_white = np.array([180, 255, 60], dtype=np.uint8)
        mask_hls = cv2.inRange(hls, lower_white, upper_white)

        warped = cv2.bitwise_or(mask_gray, mask_hls)  # shape = (H/2, W)

        # 4) Histogram over bottom–half ROI
        hist = np.sum(warped, axis=0)
        half = W // 2
        left_base  = int(np.argmax(hist[:half]))
        right_base = int(np.argmax(hist[half:]) + half)

        # 5) Sliding windows on ROI—with y indexed 0 → H/2—but map back to full image coords by adding bot_y
        nwindows, margin, minpix = 10, 100, 50
        window_h = warped.shape[0] // nwindows  # H/2 / nwindows

        nonzero = warped.nonzero()
        nonzeroy = np.array(nonzero[0]) + bot_y  # shift into full image Y
        nonzerox = np.array(nonzero[1])

        left_cur, right_cur = left_base, right_base
        left_inds, right_inds = [], []

        for w in range(nwindows):
            # sliding window boundaries in full-image coords
            y_low  = H - (w+1)*window_h
            y_high = H - w*window_h
            xll, xlh = left_cur - margin,  left_cur + margin
            xrl, xrh = right_cur - margin, right_cur + margin

            good_left  = ((nonzeroy >= y_low) & (nonzeroy < y_high) &
                          (nonzerox >= xll)   & (nonzerox < xlh)).nonzero()[0]
            good_right = ((nonzeroy >= y_low) & (nonzeroy < y_high) &
                          (nonzerox >= xrl)   & (nonzerox < xrh)).nonzero()[0]

            left_inds.append(good_left)
            right_inds.append(good_right)

            if len(good_left) > minpix:
                left_cur  = int(np.mean(nonzerox[good_left]))
            if len(good_right) > minpix:
                right_cur = int(np.mean(nonzerox[good_right]))

        left_inds  = np.concatenate(left_inds)
        right_inds = np.concatenate(right_inds)

        leftx,  lefty  = nonzerox[left_inds], nonzeroy[left_inds]
        rightx, righty = nonzerox[right_inds],nonzeroy[right_inds]

        # 6) Fit 2nd-order polynomials (with fallback)
        try:
            left_fit = np.polyfit(lefty, leftx, 2)
            self.left_fit_prev = left_fit
        except Exception:
            left_fit = self.left_fit_prev

        try:
            right_fit = np.polyfit(righty, rightx, 2)
            self.right_fit_prev = right_fit
        except Exception:
            right_fit = self.right_fit_prev

        # ← NEW GUARD TO AVOID NoneType below
        if left_fit is None or right_fit is None:
            self.get_logger().warning(
                'No valid lane fits yet; skipping this frame'
            )
            return

        # 7) Now it’s safe to compute fitx and ploty
        ploty     = np.linspace(bot_y, H-1, warped.shape[0])
        left_fitx = left_fit[0]*ploty**2 + left_fit[1]*ploty + left_fit[2]
        right_fitx= right_fit[0]*ploty**2 + right_fit[1]*ploty + right_fit[2]

        # 8) Publish numeric results
        #  8a) Center between bases
        self.lane_center_pub.publish(
            Float64(data=float((left_base + right_base)/2.0))
        )

        #  8b) Midpoints at y = bot_y (top of ROI)
        lm_x = left_fit[0]*bot_y**2  + left_fit[1]*bot_y  + left_fit[2]
        rm_x = right_fit[0]*bot_y**2 + right_fit[1]*bot_y + right_fit[2]
        self.left_mid_pub.publish (Point(x=float(lm_x), y=float(bot_y), z=0.0))
        self.right_mid_pub.publish(Point(x=float(rm_x), y=float(bot_y), z=0.0))

        #  8c) Centroid of the filled region between lanes (bottom-half only)
        pts_left  = np.vstack([left_fitx,  ploty]).T.astype(np.int32)
        pts_right = np.vstack([right_fitx, ploty]).T.astype(np.int32)
        poly      = np.vstack((pts_left, pts_right[::-1]))

        region_mask = np.zeros((H, W), dtype=np.uint8)
        cv2.fillPoly(region_mask, [poly], 255)
        ys, xs = np.nonzero(region_mask)
        if xs.size:
            cx_r, cy_r = float(xs.mean()), float(ys.mean())
        else:
            cx_r, cy_r = float(W/2), float((bot_y+H)/2)

        self.region_centroid_pub.publish(Point(x=cx_r, y=cy_r, z=0.0))

        # 9) Publish the combined binary mask (bottom half only) as mono8
        mask_full = np.zeros((H, W), dtype=np.uint8)
        mask_full[bot_y:, :] = warped
        self.mask_pub.publish(
            self.bridge.cv2_to_imgmsg(mask_full, encoding='mono8')
        )

        # 10) Overlay centroids onto the **original** image
        overlay = img.copy()
        # left midpoint (green)
        cv2.circle(overlay,
                   (int(lm_x), bot_y),
                   radius=8,
                   color=(0,255,0), thickness=-1)
        # right midpoint (blue)
        cv2.circle(overlay,
                   (int(rm_x), bot_y),
                   radius=8,
                   color=(255,0,0), thickness=-1)
        # region centroid (red)
        cv2.circle(overlay,
                   (int(cx_r), int(cy_r)),
                   radius=10,
                   color=(0,0,255), thickness=-1)

        self.overlay_pub.publish(
            self.bridge.cv2_to_imgmsg(overlay, encoding='bgr8')
        )


def main(args=None):
    rclpy.init(args=args)
    node = LaneDetector()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
