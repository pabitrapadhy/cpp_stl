cmake_minimum_required(VERSION 3.16)
project(cpp_stl)

set(CMAKE_CXX_STANDARD 17)

set(STRONG_TYPE ../StrongTypes)
set(UTILS ../Utils)

include_directories(${STRONG_TYPE})
include_directories(${UTILS})

add_executable(sort_heap main.cpp
        ${UTILS}/Utils.h
        ${STRONG_TYPE}/StrongType.h
        ${STRONG_TYPE}/StrongDataTypes.h
        ${STRONG_TYPE}/StrongTypeProperties.h)