cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled algorithms/main.cpp
        algorithms/vec3.h
        algorithms/add.cpp
        chpt8/dowhile.cpp
        experiments/pattern_print.cpp
        chpt8/while.cpp)
