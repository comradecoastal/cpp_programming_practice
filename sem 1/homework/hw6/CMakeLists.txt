cmake_minimum_required(VERSION 3.2)
project(default)

set(CMAKE_CXX_STANDARD 20)

add_executable(task1 task1.cpp SmartDoublePtr.cpp SmartDoublePtr.h)
add_executable(task2 task2.cpp Fraction.cpp Fraction.h)