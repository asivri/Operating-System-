cmake_minimum_required(VERSION 3.5)
project(Banker_s_Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Banker_s_Algorithm ${SOURCE_FILES})