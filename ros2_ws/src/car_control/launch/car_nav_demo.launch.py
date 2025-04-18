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
    #nav2_pkg
    nav2_bringup_dir = get_package_share_directory(
        'nav2_bringup'
    )
    
    #zed_wrapper
    zed_wrapper_dir = get_package_share_directory(
        'zed_wrapper'
    )
   
    #Paths
    zed_lauch_file = os.path.join(zed_wrapper_dir, 'launch', 'zed_camera.launch.py')
    rtabmap_launch_file = os.path.join(zed_wrapper_dir, 'launch', 'rtabmap.launch.py')
    nav2_launch_file = os.path.join(nav2_bringup_dir, 'launch', 'bringup_launch.py')

    #Map path 
    map_file = '/home/nvidia/map/grid_map/map_1737011764.yaml' 

    #Rivz path
    rviz_config_file = '/home/nvidia/ros2_ws/src/car_control/rviz/nav2_default_view.rviz'

    
    return LaunchDescription([
       
        #    Launch the ZED camera
        GroupAction([
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(zed_lauch_file),
                launch_arguments={
                    'camera_model': 'zed2'
                    }.items()
                    ),

        #Run the Object Detection Visualizer node
		ExecuteProcess(
			cmd=['ros2', 'run', 'obj_det_visualizer', 'obj_visualizer'],
			output='screen'
		),

        # #Lauch RTAB-MAP for SLAM or localization
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(rtabmap_launch_file),
            launch_arguments={
                'localization': 'True',
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
                'rviz': 'False',
                'rtabmapviz': 'False',
                'database_path': '/home/nvidia/.ros/rtabmap.db',
                'intial_pose': '0 0 0 0 0 0'
                }.items()
        ),
    ]),

        #Launch Nav2 for navigation
        GroupAction(
            actions=[
            SetRemap(src='/odom', dst='/zed/zed_node/odom'),
            
            IncludeLaunchDescription(
            PythonLaunchDescriptionSource(nav2_launch_file),
            launch_arguments={
                'use_sim_time': 'False',
                'autostart': 'False',
                'map': map_file, 
                'controller_frequency': '100'

            }.items()),

        

        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=['-d', rviz_config_file],
        ) 

        ])
        
        


    ])

