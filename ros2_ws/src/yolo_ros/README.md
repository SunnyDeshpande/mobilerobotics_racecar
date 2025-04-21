**Steps for running cone detection**

1. Launch yolo node and rviz2:

        ros2 launch yolo_bringup yolo.launch.py
        rviz2

2. In rviz2, add visualisation topic /yolo/dbg_image/Image.

3. To view centroid positions:

        ros2 topic echo /detect/cone_centroid