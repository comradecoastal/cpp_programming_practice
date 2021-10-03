cmake_minimum_required(VERSION 3.2)
project(default)

set(CMAKE_CXX_STANDARD 14)

add_executable(main.cpp main.cpp DynamicVector.cpp)