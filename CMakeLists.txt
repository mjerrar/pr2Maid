cmake_minimum_required(VERSION 2.8.3)
project(pr2maid)

add_compile_options(-std=c++11)

find_package(catkin   REQUIRED COMPONENTS
  roscpp
  rospy
  cv_bridge
  image_transport
  std_msgs
  sensor_msgs
  geometry_msgs
  move_base_msgs
  actionlib
  tf
  message_generation
  visualization_msgs
  OpenCV
  Eigen3
  moveit_core
  moveit_visual_tools
  moveit_ros_planning_interface
)

add_message_files(
  FILES
  LineSegment.msg
  LineSegmentList.msg
)

generate_messages(
  DEPENDENCIES
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES line line_extraction line_extraction_ros
  CATKIN_DEPENDS 
  roscpp 
  rospy 
  std_msgs 
  rostest   
  geometry_msgs
  move_base_msgs
  message_runtime
  sensor_msgs
  visualization_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME} src/PR2Maid.cpp 
        src/LegoBrick.cpp
        src/BrickList.cpp
        src/DropBin.cpp
        src/GlobalPlanner.cpp
        src/LocalPlanner.cpp
        )

add_executable(${PROJECT_NAME}_MoveitPlanner src/MoveitPlanner.cpp)
target_link_libraries(${PROJECT_NAME}_MoveitPlanner ${catkin_LIBRARIES})

add_executable(${PROJECT_NAME}_blob_node src/BlobDetector.cpp)
target_link_libraries(${PROJECT_NAME}_blob_node ${catkin_LIBRARIES})

add_library(${PROJECT_NAME}_line src/LaserLineExtractor/line.cpp)
target_link_libraries(${PROJECT_NAME}_line ${catkin_LIBRARIES})

add_library(${PROJECT_NAME}_line_extraction src/LaserLineExtractor/line_extraction.cpp)
target_link_libraries(${PROJECT_NAME}_line_extraction ${catkin_LIBRARIES})

add_library(${PROJECT_NAME}_line_extraction_ros src/LaserLineExtractor/line_extraction_ros.cpp)
target_link_libraries(${PROJECT_NAME}_line_extraction_ros line line_extraction ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_line_extraction_ros laser_line_extraction_generate_messages_cpp)

add_executable(${PROJECT_NAME}_line_extraction_node src/LaserLineExtractor/line_extraction_node.cpp)
target_link_libraries(${PROJECT_NAME}_line_extraction_node ${PROJECT_NAME}_line_extraction_ros ${catkin_LIBRARIES})

include_directories(include ${catkin_INCLUDE_DIRS})
include_directories(include ${EIGEN3_INCLUDE_DIRS})
#add_executable(global_planner src/GlobalPlanner.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)




if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
  add_rostest_gtest(allTests test/PR2Maid.test
                             test/test_main.cpp
                             test/test_LegoBrick.cpp
                             test/test_DropBin.cpp
                             test/test_BrickList.cpp
                             test/test_GlobalPlanner.cpp
                             src/LegoBrick.cpp
                             src/Utils.cpp
                             src/DropBin.cpp
                             src/BrickList.cpp
                             src/GlobalPlanner.cpp)
  target_link_libraries(allTests ${OpenCV_LIBS} ${catkin_LIBRARIES} )
endif()