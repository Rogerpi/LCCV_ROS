cmake_minimum_required(VERSION 3.10)
project(lccv_ros)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Get the information about this package's buildtime dependencies
find_package(catkin REQUIRED COMPONENTS sensor_msgs 
                                        image_transport)

find_package(lccv)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Declare that this catkin package's runtime dependencies
catkin_package(
   CATKIN_DEPENDS sensor_msgs 
                  image_transport 
                  cv_bridge
)

add_executable(lccv_ros_node src/lccv_ros_node.cpp src/lccv_ros.cpp)
add_dependencies(lccv_ros_node liblccv ${catkin_EXPORTED_TARGETS})