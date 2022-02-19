cmake_minimum_required(VERSION 3.2)
project(default)

set(CMAKE_CXX_STANDARD 20)

add_executable(randoms randoms.cpp)
add_executable(iterators iterators.cpp)
add_executable(algos algos.cpp)