
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
import csv

class ObjectTrackerNode(Node):
    def __init__(self, publish_frequency: float):
        super().__init__('object_tracker')
        self.target_distance = 1.0
        self.pos_world = np.array([0.0, 0.0, 0.0])
        self.object_count = {"Vehicle": 0, "Person": 0}
        self.objects = []
        self.memory_tolerance = 0.3
        self.csv_filename = "detected_objects.csv"
        self.create_csv()

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

    def create_csv(self):
        with open(self.csv_filename, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(["Label", "x_coord", "y_coord", "z_coord"])

    def check_same_obj(self, new_obj):
        for obj in self.objects: 
            if (new_obj[0] == obj[0]):
                dist_new_obt_to_obj = np.sqrt((obj[1] - new_obj[1])**2 + (obj[2] - new_obj[2])**2)
                if (dist_new_obt_to_obj < self.memory_tolerance):
                    return True
        return False

    def odom_callback(self, msg: Odometry):
        pose_point = msg.pose.pose.position
        self.pos_world = np.array([pose_point.x, pose_point.y, pose_point.z])

    def obj_callback(self, msg: ObjectsStamped):
        out_cmd = Twist()
        micro_ros_msg = Int32()
        det_obj = []
        if len(msg.objects) >=0:
            for object_det in msg.objects:
                det_obj.append(object_det.label)
        
        print("=============")
        print(det_obj)
        print(self.object_count)
        print(self.objects)

        for object_detect in msg.objects:
            if (object_detect.label == "Vehicle" and self.object_count["Vehicle"] < 2) or (object_detect.label=="Person" and self.object_count["Person"] == 0):

                try:
                    obj_bbox_world = object_detect.bounding_box_3d
                    obj_bbox_world_corners_kp3d = np.array(obj_bbox_world.corners)
                    obj_bbox_world_corners_arr = []
                    for corner in obj_bbox_world_corners_kp3d:
                        obj_bbox_world_corners_arr.append([corner.kp]) 
                    obj_bbox_world_centroid = np.mean(obj_bbox_world_corners_arr, axis=0)
                    print(obj_bbox_world_centroid)
                    new_obj = tuple([object_detect.label, obj_bbox_world_centroid[0][0], obj_bbox_world_centroid[0][1], obj_bbox_world_centroid[0][2]])
                    print(new_obj)

                    if not self.check_same_obj(new_obj):
                        dist_to_new_obj = np.sqrt(new_obj[1]**2 + new_obj[2]**2)
                        if dist_to_new_obj < 5.0:
                            with open(self.csv_filename, mode='a', newline='') as file:
                                writer = csv.writer(file)
                                writer.writerow(new_obj)
                            self.objects.append(new_obj)
                            self.object_count[object_detect.label] += 1

                except Exception as e:
                    print("Some error in detecting " + object_detect.label)
                    print(e)

        if self.pos_world[0] >= 2.0:
            out_cmd.linear.x = 0.0
            out_cmd.linear.y = 0.0
            out_cmd.linear.z = 0.0
        else:
            out_cmd.linear.x = 0.8
            out_cmd.linear.y = 0.0
            out_cmd.linear.z = 0.0

        self.cmd_vel_publisher.publish(out_cmd)


def main(args=None):
    rclpy.init(args=args)
    
    # Specify the frequency at which the map message should be republished (in Hz)
    publish_frequency = 1.0  # You can change this to whatever frequency you need

    # Create and spin the republisher node
    node = ObjectTrackerNode(publish_frequency)
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
