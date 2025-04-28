# mobilerobotics_racecar
Race Car for SUTD Mobile Robotics course

## Instructions to run ROSBags

### 1. ROSBag for Race Track Challenge Task 1: Straight Line Dash

1.1. To run the ROSbag:
     Open a new terminal/terminator window/tab  
     run `cd ros2_ws/racetrack_challenge_data/q1`

1.2. To view robot info on RViz:  
     Open a new terminal/terminator window/tab  
     run `rviz2 --ros-args -p use_sim_time:=true`

1.3. To publish map -> odom transform:  
     Open a new terminal/terminator window/tab  
     run `ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 map odom`

1.4. To publish odom -> base_link transform:  
     Open a new terminal/terminator window/tab  
     run `ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 odom base_link`

1.4. To publish base_link -> zed_camera_center transform:  
     Open a new terminal/terminator window/tab  
     run `ros2 run tf2_ros static_transform_publisher 0 0 0.1 0 0 0 base_link zed_camera_center`

1.5. Then pan the camera to the location that the odom gives out, you may need to ros2 topic echo and see what xyz position the odom is in, then use the rviz2 camera info the pan towards it.


-----------------------------------------


### 2. ROSBag for Race Track Challenge Task 2: Object Detection

Depending on which run you want to view, proceed to EITHER subsection "1.1.a." or "1.1.b".

2.1.a. To run the ROSbag for run 1:  
       Open a new terminal/terminator window/tab  
       run `cd ros2_ws/racetrack_challenge_data/q2/Run1`

2.1.b. To run the ROSbag for run 2:  
       Open a new terminal/terminator window/tab  
       run `cd ros2_ws/racetrack_challenge_data/q2/Run2`

2.2. To view robot info on RViz:  
     Open a new terminal/terminator window/tab  
     run `rviz2 --ros-args -p use_sim_time:=true`

2.3. To publish map -> odom transform:  
     Open a new terminal/terminator window/tab  
     run `ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 map odom`

2.4. To publish odom -> base_link transform:  
     Open a new terminal/terminator window/tab  
     run `ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 odom base_link`

2.4. To publish base_link -> zed_camera_center transform:  
     Open a new terminal/terminator window/tab  
     run `ros2 run tf2_ros static_transform_publisher 0 0 0.1 0 0 0 base_link zed_camera_center`

2.5. Then pan the camera to some object with possible label "Vehicle" or "Person", you may need to ros2 topic echo and see what xyz position the odom is in, then use the rviz2 camera info the pan towards it.


-----------------------------------------


## Instructions to run robot
  
### 1. Race Track Challenge Task 1: Straight Line Dash

Make sure all electronics are connected and powered on. This includes the Jetson, Arduino, BAtteries, and other hardware are assembled and connected correctly.

Make sure PS4 controller is paired with Jetson.

Make sure robot is at starting line within the desired lane in a place with homogeneous sunlight intensity along the lane.

1.1. To start ros communication with PS4 controller:  
     Open a new terminal/terminator window/tab  
     run `remote_control`

1.2. To start micro-ros communications between Jetson and Arduino:  
     Open a new terminal/terminator window/tab  
     run `ros2 launch car_control car_control.launch.py`

1.3. To start Zed2 Camera and its processes:  
     Open a new terminal/terminator window/tab  
     run `ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2`

1.4. To start lane-detection:  
     Open a new terminal/terminator window/tab  
     run `cd mobilerobotics_racecar/ros2_ws/src/racetrack_challenge/lane_follower/lane_follower`  
     run `python3 lane_detection_angled.py`

1.5. To start lane-tracking controller (robot moves once this is run if in auto mode on remote, toggle disable/enable by pressing 'O' button on remote):  
     Open a new terminal/terminator window/tab  
     run `cd mobilerobotics_racecar/ros2_ws/src/racetrack_challenge/lane_follower/lane_follower`  
     run `python3 lane_controller.py`

1.6. At this point, the robot will start moving within the lane. Stop it by toggling auto mode to manual or by terminating the lane_controller node.

1.7. (Optional) Adjust the lighting parameters at lines 85, 95 and 96 if the filters are too noisy and too quiet.


-----------------------------------------


### 2. Race Track Challenge Task 2: Object Detection

Make sure all electronics are connected and powered on. This includes the Jetson, Arduino, Batteries.

Make sure PS4 controller is paired with Jetson.

Ensure that detection of objects with labels other than "Vehicle" or "Person" is disabled in zed2_wrapper common config file (it should already be disabled on robot)

Make sure robot is at starting pose within the lane and facing the desired 'X' stop mark 2m away.

2.1. To start ros communication with PS4 controller:  
     Open a new terminal/terminator window/tab  
     run `remote_control`

2.2. To start micro-ros communications between Jetson and Arduino:  
     Open a new terminal/terminator window/tab  
     run `ros2 launch car_control car_control.launch.py`

2.3. To start Zed2 Camera and its processes:  
     Open a new terminal/terminator window/tab  
     run `ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2`

2.4. To start object tracker and position logger (robot moves once this is run until Zed2's Odom topic records it moving 2.0m in robot's x-direction):  
     Open a new terminal/terminator window/tab  
     run `cd mobilerobotics_racecar/ros2_ws/src/racetrack_challenge/lane_follower/lane_follower`  
     run `python3 object_tracker.py`

2.5 Once the robot has stopped, terminate the object_tracker node to retreive the CSV file of detected object positions. A new CSV file with the name is created and updated as the node is run hence it will retain data recorded on that run if it is prematurely terminated.

2.6 At this point the robot will move forward an stop approximately over the 'X' stop mark (if facing that way 2.0m apart. While doing so it will detect intended objects and record their poses relative to world frame in the CSB file "objects_detected.csv".


-----------------------------------------


### 3. Project (Round Track Loop)

3.1. Mostly the same as section "1. Race Track Challenge Task 1: Straight Line Dash"

3.2. Instead of launching lane_detection_angled.py, launch lane_detection_angled_adaptive.py
This code can adapt to differeing brightness, which made the robot movement more stable as required for a longer duration for a lap.
This code also does a bitwise AND instead of OR to filter out noise from the field grass and outside concrete by the HLS filter.
