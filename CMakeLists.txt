cmake_minimum_required(VERSION 3.15)

add_definitions(-DLEVEL_VERIFIC=2)

project(stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack main.cpp my_stack.h my_stack.cpp)