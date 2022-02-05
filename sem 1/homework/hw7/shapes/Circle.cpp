//
// Created by coastal on 10/28/21.
//

#include "Circle.h"

void Shapes::Circle::print_info() const {
    std::cout << "Circle shape with:\ndiameter = " << Ellipse::get_a_axis() << "\ncenter point: ("
              << Ellipse::get_center()[0] << ", " << Ellipse::get_center()[1] << ")" << std::endl;
}

double Shapes::Circle::get_perimeter() const {
    return Ellipse::get_perimeter();
}

double Shapes::Circle::get_area() const {
    return Ellipse::get_area();
}

double Shapes::Circle::get_diameter() const {
    return Ellipse::get_a_axis();
}

std::array<double, 2> Shapes::Circle::get_center() const {
    return Ellipse::get_center();
}

void Shapes::Circle::set_diameter(double d) {
    Ellipse::set_axes(d, d);
}

void Shapes::Circle::set_center(std::array<double, 2> c) {
    Ellipse::set_center(c);
}
