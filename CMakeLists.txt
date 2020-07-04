cmake_minimum_required(VERSION 3.16)
project(cpp_stl)

set(CMAKE_CXX_STANDARD 17)

# 1. LANDS OF PERMUTATIONS

# province of heaps
add_subdirectory("${PROJECT_SOURCE_DIR}/make_heap" "${PROJECT_SOURCE_DIR}/_output/make_heap_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/is_heap" "${PROJECT_SOURCE_DIR}/_output/is_heap_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/is_heap_until" "${PROJECT_SOURCE_DIR}/_output/is_heap_until_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/push_heap" "${PROJECT_SOURCE_DIR}/_output/push_heap_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/pop_heap" "${PROJECT_SOURCE_DIR}/_output/pop_heap_output")

# shores of sorting
add_subdirectory("${PROJECT_SOURCE_DIR}/sort_heap" "${PROJECT_SOURCE_DIR}/_output/sort_heap_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/sort" "${PROJECT_SOURCE_DIR}/_output/sort_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/inplace_merge" "${PROJECT_SOURCE_DIR}/_output/inplace_merge_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/partial_sort" "${PROJECT_SOURCE_DIR}/_output/partial_sort_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/nth_element" "${PROJECT_SOURCE_DIR}/_output/nth_element_output")

add_subdirectory("${PROJECT_SOURCE_DIR}/partition" "${PROJECT_SOURCE_DIR}/_output/partition_output")
add_subdirectory("${PROJECT_SOURCE_DIR}/partition_point" "${PROJECT_SOURCE_DIR}/_output/partition_point_output")

add_executable(cpp_stl main.cpp)