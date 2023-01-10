cmake_minimum_required(VERSION 3.0.0)
project(Video-Edges VERSION 0.1.0)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Video-Edges main.cpp)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )