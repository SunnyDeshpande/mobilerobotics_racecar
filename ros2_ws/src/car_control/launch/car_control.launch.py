from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import SetEnvironmentVariable

def generate_launch_description():
	return LaunchDescription([

		#unset ROS_DOMAIN_ID
		SetEnvironmentVariable(name='ROS_DOMAIN_ID', value=''),

		#Joy node
		Node(
			package='joy',
            executable='joy_node',
			name='joy_node',
			output='screen',
			parameters=[{'use_sim_time': False}
			]),


		#Car control node
		Node(
			package='car_control',
			executable='car_control_test',
			name='car_control_node',
			output='screen',
			# remappings=[('/camera/odom', '/zed/zed_node/odom')]
		
			)

		])