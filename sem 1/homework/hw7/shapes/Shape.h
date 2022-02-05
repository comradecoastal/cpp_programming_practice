//
// Created by coastal on 10/27/21.
//

#ifndef DEFAULT_SHAPE_H
#define DEFAULT_SHAPE_H

#include <iostream>
#include <cmath>
#include <vector>
#include <array>

namespace Shapes {
    // main class
    class Shape;

    // child classes
    class Polygon;

    class Ellipse;

    class Circle;

    class Rectangle;

    class Square;

    class Triangle;

    // pi
    static const double PI = 3.14159265359;

    // length function
    static double length(std::array<double, 2> x1, std::array<double, 2> x2);
}

class Shapes::Shape {
public:
    Shape() = default;

    // required virtual methods
    virtual double get_perimeter() const;

    virtual double get_area() const;

    virtual void print_info() const;

    // virtual destructor
    virtual ~Shape() = default;

};

double Shapes::length(std::array<double, 2> x1, std::array<double, 2> x2) {
    // compute the length of the line connecting two points (x1 and x2) on a 2d plane
    return std::sqrt(pow(x1[0] - x2[0], 2) + pow(x1[1] - x2[1], 2));
}


#endif //DEFAULT_SHAPE_H
