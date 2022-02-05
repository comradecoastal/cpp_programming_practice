cmake_minimum_required(VERSION 3.2)
project(default)

set(CMAKE_CXX_STANDARD 20)

add_executable(lesson.cpp lesson.cpp)
add_executable(task1 task1.cpp Timer.h Timer.cpp)