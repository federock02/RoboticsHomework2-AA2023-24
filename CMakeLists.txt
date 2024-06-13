cmake_minimum_required(VERSION 3.0.2)
project(second_project)

add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
      roscpp
      tf
      nav_msgs
      gmapping
      pointcloud_to_laserscan
      rviz
)

## Generate dynamic reconfigure config file
## generate_dynamic_reconfigure_options()

## Declare a catkin package
catkin_package()

## Specify additional locations of header files
include_directories(
      ${catkin_INCLUDE_DIRS}
)

## Declare C++ executables for the nodes
add_executable(odom_to_tf src/odom_to_tf.cpp)

## Add dependencies and link libraries for each executable
add_dependencies(
      odom_to_tf ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(
      odom_to_tf ${catkin_LIBRARIES}
)
