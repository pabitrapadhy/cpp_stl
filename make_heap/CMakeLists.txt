cmake_minimum_required(VERSION 3.16)
project(cpp_stl)

set(CMAKE_CXX_STANDARD 17)

set(STRONG_TYPE ../StrongTypes)

include_directories(${STRONG_TYPE})

add_executable(make_heap main.cpp
        ${STRONG_TYPE}/StrongType.h
        ${STRONG_TYPE}/StrongDataTypes.h
        ${STRONG_TYPE}/StrongTypeProperties.h)