import rclpy
from rclpy.node import Node
#from rosbag2_py import SequentialReader, StorageOptions, ConverterOptions
# from rosbag2_py.interfaces import StorageInterface
# from obj_msgs.msg import Objects
from zed_interfaces.msg import ObjectsStamped
from rclpy.serialization import deserialize_message

from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point
from std_msgs.msg import Float32MultiArray

# class BagReader(Node):
#     def __init__(self):
#         super().__init__('bag_reader')
#         self.get_logger().info("Initialized BagReader Node")

#     def read_bag_file(self, bag_file_path):
#         # Initialize the ROS 2 bag reader
#         storage_options = StorageOptions(uri=bag_file_path, storage_id='sqlite3')
#         converter_options = ConverterOptions('', '')
#         reader = SequentialReader()
#         reader.open(storage_options, converter_options)

#         # Get the available topics in the bag file
#         topic_info = reader.get_all_topics_and_types()
#         self.get_logger().info(f"Available topics in the bag: {topic_info}")

#         # Loop through all the messages in the bag file
#         while reader.has_next():
#             # Read the next message from the bag file
#             topic, msg, t = reader.read_next()
            
#             # Print message data if the topic matches the one you're interested in (obj_det/objects)
#             if topic == '/zed/zed_node/obj_det/objects':  # Adjust topic name if needed
#                 self.print_objects_message(msg)

#     def print_objects_message(self, msg):
#         # Assuming the msg is of type 'obj_msgs/Objects'
#         self.get_logger().info(f"Received {len(msg)} objects")
#         clean_msg = deserialize_message(msg, ObjectsStamped)
#         # print(clean_msg)
#         print(clean_msg.header)
        
#         # Iterate over the detected objects and print their details
#         for i, obj in enumerate(clean_msg.objects):
#             label = obj.label
#             confidence = obj.confidence
#             bounding_box = obj.bounding_box_2d
#             bounding_box_3d = obj.bounding_box_3d
#             self.get_logger().info(f"Object {i + 1}:")
#             self.get_logger().info(f"  Label: {label}")
#             self.get_logger().info(f"  Confidence: {confidence:.2f}")
#             self.get_logger().info(f"  Bounding Box: {bounding_box}")
#             self.get_logger().info(f"  Bounding_box_3d: {bounding_box_3d.corners[0].kp}")


class ObjectSubscriber(Node):

    def __init__(self):
        super().__init__('ObjectSubscriber')
        self.subscription = self.create_subscription(
            ObjectsStamped,
            '/zed/zed_node/obj_det/objects',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        # Create a publisher for the Marker message
        self.marker_pub = self.create_publisher(Marker, '/bounding_box', 10)
        
        # Create a publisher for the Float32MultiArray message
        self.publisher = self.create_publisher(Float32MultiArray, '/bounding_box_corners', 10)

    def listener_callback(self, msg):
        # self.get_logger().info('I heard: "%s"' % msg.header)
        # self.get_logger().info('I heard: "%s"' % msg.objects[0].bounding_box_3d.corners[0].kp)

        # Create and initialize the Marker message
        self.marker = Marker()
        self.marker.header.frame_id = "map"  # Coordinate frame
        self.marker.header.stamp = self.get_clock().now().to_msg()
        self.marker.ns = "bounding_box"
        self.marker.id = 0
        self.marker.type = Marker.LINE_LIST
        self.marker.action = Marker.ADD
        self.marker.scale.x = 0.1  # Line width
        self.marker.color.a = 1.0
        self.marker.color.r = 1.0
        self.marker.color.g = 0.0
        self.marker.color.b = 0.0

        for box in msg.objects:
            corners = self.find_corners(box)

            # Add the points to form the bounding box
            self.add_bounding_box_edges(corners)
            self.publish_bounding_box(corners)
            
    def publish_bounding_box(self, corners):
        """ Publish the bounding box corners using a user-defined function. """
        corners_data = [d for c in corners for d in c]
        
        if len(corners_data) != 24:
            self.get_logger().warn("The provided data doesn't contain exactly 24 floats.")
            return
        
        # Create a Float32MultiArray message
        msg = Float32MultiArray()
        msg.data = corners_data
        
        # Publish the message to the '/bounding_box_corners' topic
        self.publisher.publish(msg)
        # self.get_logger().info(f"Publishing bounding box corners: {msg.data}")

    def add_bounding_box_edges(self, corners):
        # List of the 12 edges of the cuboid (connecting the corners)
        edges = [
            [0, 1], [1, 2], [2, 3], [3, 0],  # Bottom face
            [4, 5], [5, 6], [6, 7], [7, 4],  # Top face
            [0, 4], [1, 5], [2, 6], [3, 7]   # Vertical edges
        ]
        
        # Add the points to the Marker message
        for edge in edges:
            point_start = corners[edge[0]]
            point_end = corners[edge[1]]
            
            # Create Point messages for the start and end of the edge
            p_start = Point()
            p_start.x, p_start.y, p_start.z = point_start
            
            p_end = Point()
            p_end.x, p_end.y, p_end.z = point_end
            
            # Add points to the marker
            self.marker.points.append(p_start)
            self.marker.points.append(p_end)
        
        # Publish the marker
        self.publish_marker()

    def find_corners(self, msg):
        corners_obj = msg.bounding_box_3d.corners
        corners = [[c.kp[0].item(), c.kp[1].item(), c.kp[2].item()] for c in corners_obj]
        # print(corners[0][0])
        # print(type(corners[0][0]))

        return corners

    def publish_marker(self):
        # Publish the marker to RViz
        self.marker_pub.publish(self.marker)
        self.get_logger().info("Bounding box marker published to RViz.")


# class BoundingBoxVisualizer(Node):
#     def __init__(self):
#         super().__init__('bounding_box_visualizer')
        
#         # Create a publisher for the Marker message
#         self.marker_pub = self.create_publisher(Marker, '/visualization_marker', 10)
        
#         # Define 8 corners of a cuboid (as an example)
#         # These are the 3D coordinates of the 8 corners of the bounding box
#         self.corners = [
#             [1.0, 1.0, 0.0],  # Corner 0
#             [2.0, 1.0, 0.0],  # Corner 1
#             [2.0, 2.0, 0.0],  # Corner 2
#             [1.0, 2.0, 0.0],  # Corner 3
#             [1.0, 1.0, 1.0],  # Corner 4
#             [2.0, 1.0, 1.0],  # Corner 5
#             [2.0, 2.0, 1.0],  # Corner 6
#             [1.0, 2.0, 1.0],  # Corner 7
#         ]
        
#         # Create and initialize the Marker message
#         self.marker = Marker()
#         self.marker.header.frame_id = "world"  # Coordinate frame
#         self.marker.header.stamp = self.get_clock().now().to_msg()
#         self.marker.ns = "bounding_box"
#         self.marker.id = 0
#         self.marker.type = Marker.LINE_LIST
#         self.marker.action = Marker.ADD
#         self.marker.scale.x = 0.05  # Line width
#         self.marker.color = ColorRGBA(1.0, 0.0, 0.0, 1.0)  # Red color
        
#         # Add the points to form the bounding box
#         self.add_bounding_box_edges()

#     def add_bounding_box_edges(self):
#         # List of the 12 edges of the cuboid (connecting the corners)
#         edges = [
#             [0, 1], [1, 2], [2, 3], [3, 0],  # Bottom face
#             [4, 5], [5, 6], [6, 7], [7, 4],  # Top face
#             [0, 4], [1, 5], [2, 6], [3, 7]   # Vertical edges
#         ]
        
#         # Add the points to the Marker message
#         for edge in edges:
#             point_start = self.corners[edge[0]]
#             point_end = self.corners[edge[1]]
            
#             # Create Point messages for the start and end of the edge
#             p_start = Point()
#             p_start.x, p_start.y, p_start.z = point_start
            
#             p_end = Point()
#             p_end.x, p_end.y, p_end.z = point_end
            
#             # Add points to the marker
#             self.marker.points.append(p_start)
#             self.marker.points.append(p_end)
        
#         # Publish the marker
#         self.publish_marker()

#     def publish_marker(self):
#         # Publish the marker to RViz
#         self.marker_pub.publish(self.marker)
#         self.get_logger().info("Bounding box marker published to RViz.")

def main(args=None):
    rclpy.init(args=args)
    # node = BagReader()
    node = ObjectSubscriber()
    # node2 = BoundingBoxVisualizer()

    # # Set the path to your bag file here
    # bag_file_path = '/home/nvidia/test_objdet/rosbag2_2024_12_04-10_08_28/rosbag2_2024_12_04-10_08_28_0.db3'

    # Set the publishing rate (10 Hz)
    rate = node.create_rate(10)

    # try:
    #     node.read_bag_file(bag_file_path)
    # except Exception as e:
    #     node.get_logger().error(f"Error while reading bag file: {e}")
    # finally:
    #     node.destroy_node()
    #     rclpy.shutdown()

    # while rclpy.ok():
    #     rclpy.spin_once(node)
    #     rate.sleep()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

# def main(args=None):
#     rclpy.init(args=args)
#     node = BoundingBoxVisualizer()
    
#     # Set the publishing rate (10 Hz)
#     rate = node.create_rate(10)
    
#     while rclpy.ok():
#         rclpy.spin_once(node)
#         rate.sleep()

#     node.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()
