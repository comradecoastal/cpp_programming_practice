cmake_minimum_required(VERSION 3.2)
project(default)

set(CMAKE_CXX_STANDARD 14)

add_executable(task1.cpp task1.cpp)
add_executable(task2.cpp task2.cpp Vector.cpp Vector.h)
add_executable(task3.cpp task3.cpp Length.cpp Length.h)
add_executable(task4a task4a.cpp TestClassA.cpp TestClassA.h)
add_executable(task4b task4b.cpp TestClassB.cpp TestClassB.h)