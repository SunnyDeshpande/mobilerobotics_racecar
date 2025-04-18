from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import ExecuteProcess,DeclareLaunchArgument, IncludeLaunchDescription, GroupAction, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node, SetRemap
import os



def generate_launch_description():

    # Directories
   
    #zed_wrapper
    zed_wrapper_dir = get_package_share_directory(
        'zed_wrapper'
    )
   
    #Paths
    zed_lauch_file = os.path.join(zed_wrapper_dir, 'launch', 'zed_camera.launch.py')
    rtabmap_launch_file = os.path.join(zed_wrapper_dir, 'launch', 'rtabmap.launch.py')
   

   

    

    
    return LaunchDescription([
       
        #    Launch the ZED camera
        GroupAction([
            # IncludeLaunchDescription(
            #     PythonLaunchDescriptionSource(zed_lauch_file),
            #     launch_arguments={
            #         'camera_model': 'zed2'
            #         }.items()
            #         ),

                # #Lauch RTAB-MAP for SLAM or localization
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(rtabmap_launch_file),
                launch_arguments={
                    'rtabmap_args': '--delete_db_on_start',
                    'rgb_topic': '/zed/zed_node/rgb/image_rect_color',
                    'depth_topic': '/zed/zed_node/depth/depth_registered',
                    'camera_info_topic': '/zed/zed_node/rgb/camera_info',
                    'odom_topic': '/zed/zed_node/odom',
                    'visual_odometry': 'False',
                    'frame_id': 'zed_camera_link',
                    'approx_sync': 'True',
                    'wait_imu_to_init': 'True',
                    'rgbd_sync': 'True',
                    'approx_rgbd_sync': 'True',
                    'imu_topic': '/zed/zed_node/imu/data',
                    'qos': '0',
                    'rviz': 'True',
                    'rtabmapviz': 'True'
                }.items()),
    ]),


    ])

