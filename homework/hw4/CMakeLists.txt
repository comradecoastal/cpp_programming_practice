project(default)
cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
add_executable(task1 task1.cpp Human.h Human.cpp json.hpp)
add_executable(task2 task2.cpp)
add_executable(default main.cpp)