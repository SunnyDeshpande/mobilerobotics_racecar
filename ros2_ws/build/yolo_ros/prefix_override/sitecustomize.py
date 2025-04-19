import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/gerald/mobilerobotics_racecar/ros2_ws/install/yolo_ros'
