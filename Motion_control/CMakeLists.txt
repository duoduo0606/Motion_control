cmake_minimum_required(VERSION 3.17)
project(Motion_control)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/Cellar/eigen/3.3.8_1/include/eigen3)
include_directories(/Applications/Webots.app/include/controller/cpp)

add_executable(motion src/main.cpp src/motion_control)