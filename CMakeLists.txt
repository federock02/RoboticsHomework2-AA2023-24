cmake_minimum_required(VERSION 3.0.2)
project(second_project)

add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
      roscpp
      std_msgs
      sensor_msgs
      tf
      nav_msgs
      pointcloud_to_laserscan
      rviz
      move_base
      stage_ros
      map_server
)

## Declare a catkin package
catkin_package()

## Specify additional locations of header files
include_directories(
      ${catkin_INCLUDE_DIRS}
)

## Declare C++ executables for the nodes
add_executable(odom_to_base_link src/odom_to_base_link.cpp)
add_executable(lidar_remap src/lidar_remap.cpp)
add_executable(goal_publisher src/goal_publisher.cpp)

## Add dependencies and link libraries for each executable
add_dependencies(odom_to_base_link ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(lidar_remap ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(goal_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(odom_to_base_link ${catkin_LIBRARIES})
target_link_libraries(lidar_remap ${catkin_LIBRARIES})
target_link_libraries(goal_publisher ${catkin_LIBRARIES})
