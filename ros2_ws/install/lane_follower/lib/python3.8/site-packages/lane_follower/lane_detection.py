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

        self.bridge = CvBridge()

        # subscription
        self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',
            self.image_callback,
            10
        )

        # plain numeric publishers
        self.lane_center_pub     = self.create_publisher(Float64, '/detect/lane',                 10)
        self.left_mid_pub        = self.create_publisher(Point,   '/detect/lane_left_midpoint',  10)
        self.right_mid_pub       = self.create_publisher(Point,   '/detect/lane_right_midpoint', 10)
        self.region_centroid_pub = self.create_publisher(Point,   '/detect/lane_region_centroid',10)

        # image publishers
        self.mask_pub    = self.create_publisher(Image, '/camera/mask_lane_detected',    10)
        self.overlay_pub = self.create_publisher(Image, '/camera/centroid_overlay',     10)

        # to remember last fit if poly fails
        self.left_fit_prev  = None
        self.right_fit_prev = None

    def image_callback(self, msg: Image):
        # 1. Convert to OpenCV BGR
        img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        H, W = img.shape[:2]

        # 2. Grayscale + blur + threshold for white on red track
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        gray = cv2.medianBlur(gray, 9)
        _, mask_gray = cv2.threshold(gray, 200, 255, cv2.THRESH_BINARY)

        # 3. HLS threshold for white
        hls = cv2.cvtColor(img, cv2.COLOR_BGR2HLS)
        lower_white = np.array([0, 200,  0], dtype=np.uint8)
        upper_white = np.array([180,255, 60], dtype=np.uint8)
        mask_hls = cv2.inRange(hls, lower_white, upper_white)

        # 4. Combined binary mask
        warped = cv2.bitwise_or(mask_gray, mask_hls)

        # 5. Histogram + sliding windows to find lane line pixels
        hist      = np.sum(warped[H//2:, :], axis=0)
        half      = W // 2
        left_base = int(np.argmax(hist[:half]))
        right_base= int(np.argmax(hist[half:]) + half)

        nwindows, margin, minpix = 10, 100, 50
        window_h = H // nwindows
        nonzero  = warped.nonzero()
        nonzeroy = np.array(nonzero[0])
        nonzerox = np.array(nonzero[1])
        left_cur, right_cur = left_base, right_base

        left_inds, right_inds = [], []
        for w in range(nwindows):
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

            if len(good_left)  > minpix:
                left_cur  = int(np.mean(nonzerox[good_left]))
            if len(good_right) > minpix:
                right_cur = int(np.mean(nonzerox[good_right]))

        left_inds  = np.concatenate(left_inds)
        right_inds = np.concatenate(right_inds)
        leftx,  lefty  = nonzerox[left_inds],  nonzeroy[left_inds]
        rightx, righty = nonzerox[right_inds], nonzeroy[right_inds]

        # 6. Fit 2nd‐order polynomials (with fallback)
        try:
            left_fit  = np.polyfit(lefty,  leftx,  2)
            self.left_fit_prev = left_fit
        except Exception:
            left_fit = self.left_fit_prev

        try:
            right_fit = np.polyfit(righty, rightx, 2)
            self.right_fit_prev = right_fit
        except Exception:
            right_fit = self.right_fit_prev

        # 7. Generate x positions along each fit
        ploty      = np.linspace(0, H-1, H)
        left_fitx  = left_fit[0]*ploty**2  + left_fit[1]*ploty  + left_fit[2]
        right_fitx = right_fit[0]*ploty**2 + right_fit[1]*ploty + right_fit[2]

        # 8. Publish numeric topics
        #   center between lane bases
        center_x = Float64(data=float((left_base + right_base) / 2.0))
        self.lane_center_pub.publish(center_x)

        #   left/right midpoints at half‐height
        mid_y = H / 2.0
        left_mid_x  = left_fit[0]*mid_y**2  + left_fit[1]*mid_y  + left_fit[2]
        right_mid_x = right_fit[0]*mid_y**2 + right_fit[1]*mid_y + right_fit[2]

        self.left_mid_pub.publish(Point(x=float(left_mid_x),  y=mid_y, z=0.0))
        self.right_mid_pub.publish(Point(x=float(right_mid_x), y=mid_y, z=0.0))

        #   centroid of region between lanes
        pts_left  = np.vstack([left_fitx,  ploty]).T.astype(np.int32)
        pts_right = np.vstack([right_fitx, ploty]).T.astype(np.int32)
        poly      = np.vstack((pts_left, pts_right[::-1]))
        region_mask = np.zeros_like(warped, dtype=np.uint8)
        cv2.fillPoly(region_mask, [poly], 255)

        ys, xs = np.nonzero(region_mask)
        if xs.size:
            cx_r = float(xs.mean())
            cy_r = float(ys.mean())
        else:
            cx_r = float(W / 2.0)
            cy_r = float(H / 2.0)

        self.region_centroid_pub.publish(Point(x=cx_r, y=cy_r, z=0.0))

        # 9. Publish binary mask
        mask_msg = self.bridge.cv2_to_imgmsg(warped, encoding='mono8')
        self.mask_pub.publish(mask_msg)

        # 10. Overlay centroids on original image
        overlay = img.copy()

        # left midpoint (green)
        cv2.circle(overlay,
                   (int(left_mid_x), int(mid_y)),
                   radius=8,
                   color=(0,255,0),
                   thickness=-1)

        # right midpoint (blue)
        cv2.circle(overlay,
                   (int(right_mid_x), int(mid_y)),
                   radius=8,
                   color=(255,0,0),
                   thickness=-1)

        # region centroid (red)
        cv2.circle(overlay,
                   (int(cx_r), int(cy_r)),
                   radius=10,
                   color=(0,0,255),
                   thickness=-1)

        # publish overlay
        out_msg = self.bridge.cv2_to_imgmsg(overlay, encoding='bgr8')
        self.overlay_pub.publish(out_msg)


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
