cmake_minimum_required(VERSION 3.5)
project(Page_Replacement_Algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Page_Replacement_Algorithms ${SOURCE_FILES})