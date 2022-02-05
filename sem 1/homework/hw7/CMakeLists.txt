cmake_minimum_required(VERSION 3.2)
project(default)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp
        shapes/Shape.cpp shapes/Shape.h
        shapes/Polygon.cpp shapes/Polygon.h
        shapes/Ellipse.cpp shapes/Ellipse.h
        shapes/Circle.h shapes/Circle.cpp
        shapes/Rectangle.cpp shapes/Rectangle.h
        shapes/Square.cpp shapes/Square.h
        shapes/Triangle.h shapes/Triangle.cpp)