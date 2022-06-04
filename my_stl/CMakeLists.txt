cmake_minimum_required(VERSION 3.20)
project(play_with_algo)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES list.h test_list.cpp)
add_executable(play_with_algo ${SOURCE_FILES})
