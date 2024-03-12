cmake_minimum_required(VERSION 3.10)
project(lab2)
# set(OpenCV_DIR C:/Users/Dmitriy Novichkov/Desktop/opencv/build)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
add_executable(${PROJECT_NAME} 1.cpp)
target_link_libraries(${PROJECT_NAME} ${OPENCV_LIBS})