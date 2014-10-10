cmake_minimum_required(VERSION 2.8.3)
project(naoqi_launcher)

find_package(qibuild)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES publisher
  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS naoqi
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

set(_srcs
    src/main.cpp
    src/publisher.cpp
    src/publisher.h
)

#qi_create_lib(publisher SHARED ${_srcs} SUBFOLDER naoqi)

add_library(publisher src/main.cpp src/publisher.cpp)

qi_use_lib(publisher ALCOMMON ALMEMORYFASTACCESS)
target_link_libraries(publisher
   ${catkin_LIBRARIES}
)

# Also create an executable to start and stop capture
qi_create_bin(testPublisher src/testPublisher.cpp)
qi_use_lib(testPublisher ALCOMMON)
