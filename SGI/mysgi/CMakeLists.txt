cmake_minimum_required(VERSION 3.20)
project(play_with_algo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES TestMain.cpp stl_alloc.h stl_config.h stl_construct.h stl_iterator.h stl_vector.h type_traits.h stl_algobase.h stl_uninitialized.h)
add_executable(play_with_algo ${SOURCE_FILES})
