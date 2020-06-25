cmake_minimum_required(VERSION 3.16)
project(cpp_stl)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${PROJECT_SOURCE_DIR}/make_heap" "${PROJECT_SOURCE_DIR}/make_heap/make_heap_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/push_heap" "${PROJECT_SOURCE_DIR}/push_heap/push_heap_output")
