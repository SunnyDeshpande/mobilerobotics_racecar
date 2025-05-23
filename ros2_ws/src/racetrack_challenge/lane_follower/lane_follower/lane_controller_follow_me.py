#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64
from geometry_msgs.msg import Point, Twist

from rclpy.qos import QoSProfile, ReliabilityPolicy

import numpy as np

class LaneDetector(Node):
    def __init__(self):
        super().__init__('lane_controller')
        self.get_logger().info('Lane controller node started')
        self.image_size_x = 160.0 #320.0
        self.image_size_y = 120.0 #240.0
        self.dist_scale_factor = 0.5
        self.steer_scale_factor = 0.03
        self.fwd_speed = 0.7 #0.3

        # Create a subscriber to the '/zed/zed_node/obj_det/objects' topic
        self.obj_subscription = self.create_subscription(
            ObjectsStamped,
            '/zed/zed_node/obj_det/objects',
            self.obj_callback,
            QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        )

###

corners = object.bounding_box_2d.corners  # list of Point2D
x_vals = [c.x for c in corners]
y_vals = [c.y for c in corners]
centroid_x = sum(x_vals) / len(x_vals)
centroid_y = sum(y_vals) / len(y_vals)

####
        # Numeric publishers
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE))

    def obj_callback(self, msg: Point):
        if len(msg.objects) >=0:
            if msg.objects[0].label == "Vehicle"




        centroid_x = msg.x
        centroid_y = msg.y

        img_centre_x = self.image_size_x/2
        img_centre_y = self.image_size_y/2

        cmd_vel_msg = Twist()
        cmd_vel_msg.linear.x = self.fwd_speed
        cmd_vel_msg.linear.y = 0.0
        cmd_vel_msg.linear.z = 0.0

        cmd_vel_msg.angular.x = 0.0
        cmd_vel_msg.angular.y = 0.0

        err_x = centroid_x - img_centre_x
        # print(err_x)
        dist_from_robot = 1.0 / (1.0 - ((max(img_centre_y, centroid_y) - img_centre_y)/img_centre_y) + 0.05) # 0.05 to avoid divide-by-zero
        dist_scale = min(1.0, self.dist_scale_factor*dist_from_robot)
        steer_val = -dist_scale * self.steer_scale_factor * err_x

        cmd_vel_msg.angular.z = steer_val-0.01
        self.cmd_vel_pub.publish(cmd_vel_msg)
        pass


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
