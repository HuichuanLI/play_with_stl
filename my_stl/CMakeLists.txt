cmake_minimum_required(VERSION 3.20)
project(play_with_algo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  test/test_biset_stack_application.cpp test/test_bitset_applcation.cpp)
add_executable(play_with_algo ${SOURCE_FILES})
