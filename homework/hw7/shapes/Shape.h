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
    class Shape;

    class Polygon;

    class Ellipse;

    class Circle;

    class Rectangle;

    class Square;

    class Triangle;

    static const double PI = 3.14159265359;

    static double length(std::array<double, 2> x1, std::array<double, 2> x2);

//    static double measure(std::array<double, 2> x1, std::array<double, 2> x2, std::array<double, 2> x3);
}

class Shapes::Shape {
public:
    Shape() = default;

    virtual double get_perimeter() const;

    virtual double get_area() const;

    virtual void print_info() const;

    friend std::ostream &operator<<(std::ostream &, const Shape &);

    virtual ~Shape() = default;

};

double Shapes::length(std::array<double, 2> x1, std::array<double, 2> x2) {
    // compute the length of the line connecting two points (x1 and x2) on a 2d plane
    return std::sqrt(pow(x1[0] - x2[0], 2) + pow(x1[1] - x2[1], 2));
}

//double Shapes::measure(std::array<double, 2> x1, std::array<double, 2> x2, std::array<double, 2> x3) {
//    // compute the area of a triangle defined by 3 vertices (x1, x2 and x3) on a 2d plane
//    return 0.5 * std::abs(x1[0] * (x2[1] - x3[1]) + x3[0] * (x1[1] - x2[1]) +x2[0] * (x3[1] - x1[1]));
//}

#endif //DEFAULT_SHAPE_H
