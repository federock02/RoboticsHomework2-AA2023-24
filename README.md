Format: ROS Bag file
play the bag with the command:
rosbag play --clock robotics.bag

Data:
- /ugv/odom odometry from encoders
- /ugv/rslidar_points pointcloud from lidar

*Task 1 - Mapping*
- Use the bag to create a map of the environment
  - Use the preferred mapping package
  - Write a launch file that starts:
    - all required nodes to perform data conversion
    - the mapping node
    - rviz with config file to show the map, the lidar and the tf, set global frame to map
  - You can use pointcloud_to_laserscan package to convert the pointcloud data

*Task 2 - Navigation*
- Setup a realistic simulation of the robot using real robot data and the map created in task 1 (using stage)
- Robot data available here: https://global.agilex.ai/products/scout-mini
- Setup the navigation stack to receive goals and move the simulated robot avoiding obstacles in the generated map
- Write a goal-publisher node that reads a sequence of goals from a csv and send them to the robot. A new goal is sent when the robot reach the previous one or it’s aborted
- an example csv file is provided
- Provide a launch file that starts:
  - stage simulation with the robot and the map
  - movebase configured to localize in the provided map and drive autonomously the robot avoiding obstacles
  - the controller node that publish the goal after reading them from csv
  - csv structure: x,y,theta
  - rviz configured to visualize the map, the tfs, the particle cloud (if amcl is used), the laser scanner, the paths and the goals
- Also provide a map folder with:
  - png file of the reconstructed map (mandatory)
  - serialized map if slam toolbox is used

Files: https://goo.gl/GonArW
