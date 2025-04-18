
#!/usr/bin/env python 
# Script to republish map topic at a consistent frequency with current time. Generated using ChatGPT
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist
from nav_msgs.msg import OccupancyGrid, Odometry
from rclpy.qos import QoSProfile, ReliabilityPolicy
from time import sleep
from rclpy.time import Time
from zed_interfaces.msg import ObjectsStamped
import numpy as np

class BagChaserNode(Node):
    def __init__(self, publish_frequency: float):
        super().__init__('bag_chaser')
        self.target_distance = 1.0
        self.pos_world = np.array([0.0, 0.0, 0.0])
        
        # Create a subscriber to the '/zed/zed_node/obj_det/objects' topic
        self.obj_subscription = self.create_subscription(
            ObjectsStamped,
            '/zed/zed_node/obj_det/objects',
            self.obj_callback,
            QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        )

        self.odom_subscription = self.create_subscription(
            Odometry,
            '/zed/zed_node/odom',
            self.odom_callback,
            QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        )

        # Create a publisher to publish the same message
        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            '/cmd_vel',
            QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE)#ReliabilityPolicy.BEST_EFFORT)
        )

        # self.micro_ros_publisher = self.create_publisher(
        #     Int32,
        #     '/micro_ros_arduino_subscriber',
        #     QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        # )

    def odom_callback(self, msg: Odometry):
        pose_point = msg.pose.pose.position
        self.pos_world = np.array([pose_point.x, pose_point.y, pose_point.z])

    def obj_callback(self, msg: ObjectsStamped):
        out_cmd = Twist()
        micro_ros_msg = Int32()

        try:
            obj_bbox_world = msg.objects[0].bounding_box_3d
            obj_bbox_world_corners_kp3d = np.array(obj_bbox_world.corners)
            obj_bbox_world_corners_arr = []
            for corner in obj_bbox_world_corners_kp3d:
                obj_bbox_world_corners_arr.append([corner.kp]) 
            obj_bbox_world_centroid = np.mean(obj_bbox_world_corners_arr, axis=0)
            dist_vector_to_obj = self.pos_world - obj_bbox_world_centroid
            dist_to_obj = np.sqrt(dist_vector_to_obj[0][0]**2 + dist_vector_to_obj[0][1]**2 + dist_vector_to_obj[0][2]**2)

            print(f"Object Centroid Distance: {dist_to_obj}m")

            if (dist_to_obj >= 1.0):
                out_cmd.linear.x = 1.0
                out_cmd.linear.y = 0.0
                out_cmd.linear.z = 0.0

                micro_ros_msg.data = 97115

            else:
                out_cmd.linear.x = 0.0
                out_cmd.linear.y = 0.0
                out_cmd.linear.z = 0.0

                micro_ros_msg.data = 97115 #97100
            
            self.cmd_vel_publisher.publish(out_cmd)
            #self.micro_ros_publisher.publish(micro_ros_msg)

        except Exception as e:
            print("NO OBJ")
            print(e)
            out_cmd.linear.x = 0.0
            out_cmd.linear.y = 0.0
            out_cmd.linear.z = 0.0
            self.cmd_vel_publisher.publish(out_cmd)

def main(args=None):
    rclpy.init(args=args)
    
    # Specify the frequency at which the map message should be republished (in Hz)
    publish_frequency = 1.0  # You can change this to whatever frequency you need

    # Create and spin the republisher node
    node = BagChaserNode(publish_frequency)
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
