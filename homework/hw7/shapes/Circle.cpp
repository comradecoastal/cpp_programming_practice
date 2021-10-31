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
