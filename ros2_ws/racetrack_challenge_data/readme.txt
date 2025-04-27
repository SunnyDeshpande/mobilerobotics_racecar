To run straight line dash code:
1. Run the same commands for car control & launching of zed2 camera
2. Go to src/racetrack_challenge/lane_follower/lane_follower
3. Run "python3 lane_detection_angled_backup.py" or lane_detection_angled_dark.py dpending on the conditions
- For the challenge, it should be lane_detection_angled_backup.py

To view rosbag for straight line dash code:
1. ros2 bag play race_track_q1 --clock
2. rviz2 --ros-args -p use_sim_time:=true
3. ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 map odom
4. ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 odom base_link
5. ros2 run tf2_ros static_transform_publisher 0 0 0.1 0 0 0 base_link zed_camera_center
6. Then pan the camera to the location that the odom gives out, you may need to ros2 topic echo and see what xyz position the odom is in, then use the rviz2 camera info the pan towards it.


To run object detection code:


To view rosbag for object detection: