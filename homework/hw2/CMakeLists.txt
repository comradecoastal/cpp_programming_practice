cmake_minimum_required(VERSION 3.2)
project(default)

set(CMAKE_CXX_STANDARD 20)

add_executable(time task1.cpp)
add_executable(phonebook task2.cpp Phonebook.h)