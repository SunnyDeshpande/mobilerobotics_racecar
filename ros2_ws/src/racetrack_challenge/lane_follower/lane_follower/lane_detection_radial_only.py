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
        self.lane_threshold_val = 70 # 90 if nice and bright (project), 60 if shady (project2_sunny), 150 if indoors bright (indoors)
        self.bridge = CvBridge()

        # Subscribe to the ZED left color rectified image
        self.create_subscription(
            Image,
            '/zed/zed_node/rgb/image_rect_color', #rgb for all bags but project2_sunny -> '/zed/zed_node/left/image_rect_color'
            self.image_callback,
            10
        )

        # Numeric publishers
        self.lane_center_pub     = self.create_publisher(Float64, '/detect/lane',                 10)
        self.left_mid_pub        = self.create_publisher(Point,   '/detect/lane_left_midpoint',  10)
        self.right_mid_pub     = self.create_publisher(Point,   '/detect/lane_right_midpoint', 10)
        self.region_centroid_pub = self.create_publisher(Point,   '/detect/lane_region_centroid',10)

        # Image publishers
        self.mask_pub    = self.create_publisher(Image, '/camera/mask_lane_detected', 10)
        self.denoised_pub = self.create_publisher(Image, '/camera/denoised', 10)
        self.gray_image_pub = self.create_publisher(Image, '/camera/gray', 10)
        self.gray_mask_pub = self.create_publisher(Image, '/camera/grey_mask', 10)
        self.hls_mask_pub = self.create_publisher(Image, '/camera/hls_mask', 10)
        self.overlay_pub = self.create_publisher(Image, '/camera/centroid_overlay',   10)

        # Remember last fit if polyfit fails
        self.left_fit_prev  = None
        self.right_fit_prev = None

        self.prev_left_base = None
        self.prev_right_base = None
        self.smooth_factor = 0.7  # Adjust between 0-1 (higher = more smoothing)

    def image_callback(self, msg: Image):
        # 1) Convert ROS Image → OpenCV BGR
        img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        H, W = img.shape[:2]
        # print("W: " + str(H) + " H: " + str(H))

        # 2) Define bottom half ROI
        bot_y = int(2.1*H // 3)
        roi    = img[bot_y:, :]           # shape = (H/2, W, 3)

        # # 2a) Denoise the ROI (colored)
        # roi2 = cv2.fastNlMeansDenoisingColored(
        # roi,      # input
        # None,     # output; let the function allocate
        # h=2,     # filter strength for luminance
        # hColor=2,# filter strength for color components
        # templateWindowSize=17,
        # searchWindowSize=20
        # )

        # self.denoised_pub.publish(
        #     self.bridge.cv2_to_imgmsg(roi, encoding='bgr8')
        # )

        # 3) Threshold ROI to get binary mask of white lanes
        gray = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
        #gray = cv2.medianBlur(gray, 9)
        self.gray_image_pub.publish(
            self.bridge.cv2_to_imgmsg(gray, encoding='mono8')
        )
        _, mask_gray = cv2.threshold(gray, self.lane_threshold_val, 255, cv2.THRESH_BINARY) 

        # Testing adaptive threshold
        mask_gray = cv2.adaptiveThreshold(
            gray, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, 
            cv2.THRESH_BINARY, 51, -50 #-20 for dark
        )



        self.gray_mask_pub.publish(
            self.bridge.cv2_to_imgmsg(mask_gray, encoding='mono8')
        )

        hls = cv2.cvtColor(roi, cv2.COLOR_BGR2HLS)
        lower_white = np.array([0, 90,  0], dtype=np.uint8) # 0, 40, 0 for dark
        upper_white = np.array([180, 255, 70], dtype=np.uint8)

        mask_hls = cv2.inRange(hls, lower_white, upper_white)
        
        self.hls_mask_pub.publish(
            self.bridge.cv2_to_imgmsg(mask_hls, encoding='mono8')
        )

        warped = cv2.bitwise_or(mask_gray, mask_hls)  # shape = (H/2, W)

        # 4) Histogram over bottom–half ROI
        hist = np.sum(warped, axis=0)
        half = W // 2
        left_base  = int(np.argmax(hist[:half]))
        right_base = int(np.argmax(hist[half:]) + half)

        # TEST: Angled summing with weights
        # Angle-aware weighting
        hist = np.zeros(W, dtype=np.float32)
        ray_thickness = 3
        vp_x = W // 2
        vp_y = bot_y - 15
        left_hist = np.zeros(H - bot_y, dtype=np.float32)
        right_hist = np.zeros(H - bot_y, dtype=np.float32)


        height, width = warped.shape
        H_full = bot_y + height

        # Convert vp_y to relative to ROI
        vp_y_rel = vp_y# - bot_y

        # --- 1. Bottom-origin rays ---
        for x in range(width):
            start = (x, height - 1)
            end = (vp_x, vp_y_rel)
            line = np.linspace(start, end, num=height, dtype=np.int32)

            total_sum = 0
            for dx in range(-ray_thickness, ray_thickness + 1):
                shifted = line.copy()
                shifted[:, 0] = np.clip(shifted[:, 0] + dx, 0, width - 1)
                shifted[:, 1] = np.clip(shifted[:, 1], 0, height - 1)

                total_sum += np.sum(warped[shifted[:, 1], shifted[:, 0]])

            hist[x] += total_sum

        # --- 2. Left-edge rays ---
        for y_full in range(bot_y, H_full):
            y_rel = y_full - bot_y
            start = (0, y_rel)
            end = (vp_x, vp_y_rel)
            line = np.linspace(start, end, num=width, dtype=np.int32)

            total_sum = 0
            for dx in range(-ray_thickness, ray_thickness + 1):
                shifted = line.copy()
                shifted[:, 0] = np.clip(shifted[:, 0] + dx, 0, width - 1)
                shifted[:, 1] = np.clip(shifted[:, 1], 0, height - 1)

                total_sum += np.sum(warped[shifted[:, 1], shifted[:, 0]])


            left_hist[y_full - bot_y] += total_sum

        # --- 3. Right-edge rays ---
        for y_full in range(H_full, bot_y, -1):
            y_rel = y_full - bot_y
            start = (width - 1, y_rel)
            end = (vp_x, vp_y_rel)
            line = np.linspace(start, end, num=width, dtype=np.int32)

            total_sum = 0
            for dx in range(-ray_thickness, ray_thickness + 1):
                shifted = line.copy()
                shifted[:, 0] = np.clip(shifted[:, 0] + dx, 0, width - 1)
                shifted[:, 1] = np.clip(shifted[:, 1], 0, height - 1)

                total_sum += np.sum(warped[shifted[:, 1], shifted[:, 0]])

            right_hist[-(y_full - H_full)] += total_sum

        # 1. Slice the horizontal histogram
        hist_left  = hist[:half]
        hist_right = hist[half:]

        # 2. Concatenate side histograms (same pixel units!)
        hist_left_combined = np.concatenate((left_hist, hist_left))
        hist_right_combined = np.concatenate((hist_right, right_hist))
        full_hist = np.concatenate((left_hist, hist, right_hist))


        def smooth_histogram(hist, kernel_size=15):
            """Apply Gaussian smoothing to a histogram"""
            # Create a Gaussian kernel
            x = np.linspace(-1, 1, kernel_size)
            kernel = np.exp(-(x**2)/0.2)
            # Normalize kernel
            kernel = kernel / np.sum(kernel)
            # Apply convolution for smoothing
            smoothed = np.convolve(hist, kernel, mode='same')
            return smoothed

        # Apply smoothing to the histograms
        hist_smooth = smooth_histogram(hist)
        left_hist_smooth = smooth_histogram(left_hist)
        right_hist_smooth = smooth_histogram(right_hist)

        # Now use the smoothed histograms for finding peaks
        hist_left_smooth = hist_smooth[:half]
        hist_right_smooth = hist_smooth[half:]

        # Concatenate side histograms with smoothed values
        hist_left_combined_smooth = np.concatenate((left_hist_smooth, hist_left_smooth))
        hist_right_combined_smooth = np.concatenate((hist_right_smooth, right_hist_smooth))
        full_hist = np.concatenate((hist_left_combined_smooth, hist_right_combined_smooth))

        def find_base_in_window(hist, window_size=30):
            """Find the strongest base point using a sliding window approach"""
            # Create a window kernel
            window = np.ones(window_size)
            
            # Convolve the histogram with the window to get sum of values within window
            # This effectively calculates the "strength" of each possible base location
            windowed_hist = np.convolve(hist, window, mode='same')
            
            # Find the position with maximum sum
            max_idx = np.argmax(windowed_hist)
            return max_idx

        # For left lane base
        hist_left_smooth = hist_smooth[:half]
        left_window_idx = find_base_in_window(hist_left_combined_smooth)
        left_base = left_window_idx

        # For right lane base
        hist_right_smooth = hist_smooth[half:]
        right_window_idx = find_base_in_window(hist_right_combined_smooth)
        right_base = right_window_idx + half + len(left_hist)

        # Determine if lanes start from sides
        from_side_left = left_window_idx < len(left_hist)
        from_side_right = right_window_idx >= len(hist_right_smooth)

        # 3. Find base positions
        # left_peak_idx = np.argmax(hist_left_combined)
        # right_peak_idx = np.argmax(hist_right_combined)

        # left_base = left_peak_idx
        # right_base = right_peak_idx + half + len(left_hist)  # adjust for true index in global range

        # from_side_left = left_peak_idx < len(left_hist)
        # from_side_right = right_peak_idx >= len(hist[half:])

        print("left_base:", left_base, "from_side_left:", from_side_left)
        print("right_base:", right_base, "from_side_right:", from_side_right)

        if self.prev_left_base is not None:
            # Apply exponential smoothing
            left_base = int(self.smooth_factor * self.prev_left_base + (1 - self.smooth_factor) * left_base)
            right_base = int(self.smooth_factor * self.prev_right_base + (1 - self.smooth_factor) * right_base)

        # Store for next frame
        self.prev_left_base = left_base
        self.prev_right_base = right_base

        # Instead of sliding windows, just draw direct lines from vanishing point
        # After determining from_side_left and from_side_right

        # For the left lane line
        if from_side_left:
            # Lane starts from left edge
            # Find the y-coordinate first
            left_y_start = bot_y + np.argmax(left_hist)
            # Create line from the left edge to the vanishing point
            left_pts = np.linspace(
                (0, left_y_start),  # Left edge point
                (vp_x, vp_y),       # Vanishing point
                num=warped.shape[0], 
                dtype=np.int32
            )
            left_line = np.vstack([left_pts[:, 0], left_pts[:, 1]]).T
        else:
            # Lane starts from bottom
            # Create line from bottom to vanishing point
            left_pts = np.linspace(
                (left_base, H-1),   # Bottom point
                (vp_x, vp_y),       # Vanishing point
                num=warped.shape[0], 
                dtype=np.int32
            )
            left_line = np.vstack([left_pts[:, 0], left_pts[:, 1]]).T

        # For the right lane line
        if from_side_right:
            # Lane starts from right edge
            # Find the y-coordinate first
            right_y_start = bot_y + (len(right_hist)-np.argmax(right_hist))
            # Create line from the right edge to the vanishing point
            right_pts = np.linspace(
                (W-1, right_y_start), # Right edge point
                (vp_x, vp_y),         # Vanishing point
                num=warped.shape[0], 
                dtype=np.int32
            )
            right_line = np.vstack([right_pts[:, 0], right_pts[:, 1]]).T
        else:
            # Lane starts from bottom
            # Create line from bottom to vanishing point
            right_pts = np.linspace(
                (right_base, H-1),  # Bottom point
                (vp_x, vp_y),       # Vanishing point
                num=warped.shape[0], 
                dtype=np.int32
            )
            right_line = np.vstack([right_pts[:, 0], right_pts[:, 1]]).T


        # # Use these lines directly instead of polynomial fitting
        # # To get the lane midpoint at bot_y:
        if left_line is not None:
            # Find the point where y = bot_y
            bot_y_idx = np.argmin(np.abs(left_line[:, 1] - bot_y))
            lm_x = float(left_line[bot_y_idx, 0])
        else:
            lm_x = 0.0  # Default if no left line

        if right_line is not None:
            # Find the point where y = bot_y
            bot_y_idx = np.argmin(np.abs(right_line[:, 1] - bot_y))
            rm_x = float(right_line[bot_y_idx, 0])
        else:
            rm_x = float(W)  # Default to right edge if no right line


        # # Calculate centroid
        cx_r = float((lm_x + rm_x) / 2)
        cy_r = float(bot_y)

        # Publish the midpoints
        self.left_mid_pub.publish(Point(x=lm_x, y=float(bot_y), z=0.0))
        self.right_mid_pub.publish(Point(x=rm_x, y=float(bot_y), z=0.0))
        self.region_centroid_pub.publish(Point(x=cx_r, y=cy_r, z=0.0))

        # cx_r = int(lm_x+rm_x)/2
        # cy_r = float(bot_y)
        

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

        # TEST: Debug windows
        # Create a colored visualization of the sliding windows
        window_img = np.zeros((H, W, 3), dtype=np.uint8)

        # Blend with original image for context
        alpha = 0.7
        debug_img = cv2.addWeighted(img, alpha, window_img, 1-alpha, 0)
        for base_x, color in [(left_base, (0, 255, 0)), (right_base, (255, 0, 0))]:  # green, blue
            for pt in left_line:
                cv2.circle(debug_img, (pt[0], pt[1]), radius=0, color=(0,255,0), thickness=1)
            for pt in right_line:
                cv2.circle(debug_img, (pt[0], pt[1]), radius=0, color=(255,0,0), thickness=1)


        # Add histogram visualization at the bottom
        hist_height = 100
        hist_img = np.zeros((hist_height, W+len(left_hist)+len(right_hist), 3), dtype=np.uint8)
        if np.max(full_hist) > 0:
            hist_normalized = full_hist / np.max(full_hist) * hist_height
        else:
            hist_normalized = np.zeros_like(full_hist)
        for i, h in enumerate(hist_normalized.astype(int)):
            if not np.isnan(h):
                cv2.line(hist_img, (i, hist_height), (i, int(hist_height - h)), (255, 255, 255), 1)


        # Combine main image with histogram
        combined_width = 54 + W + 54  # Left margin + image + right margin
        combined_height = H + hist_height
        combined_img = np.zeros((combined_height, combined_width, 3), dtype=np.uint8)

        # Pad debug_img horizontally to include left/right histograms
        #combined_img[:H, 0:50] = left_hist_img
        combined_img[:H, 50:50+W] = debug_img
        #combined_img[:H, 50+W:] = right_hist_img
        combined_img[H:, :] = hist_img  # Bottom histogram centered under main image


        # Create a publisher for the debug image
        if not hasattr(self, 'window_debug_pub'):
            self.window_debug_pub = self.create_publisher(Image, '/camera/sliding_windows_debug', 10)

        # Publish the debug image
        self.window_debug_pub.publish(
            self.bridge.cv2_to_imgmsg(combined_img, encoding='bgr8')
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
