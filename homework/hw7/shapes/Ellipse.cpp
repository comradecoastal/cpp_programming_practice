//
// Created by coastal on 10/28/21.
//

#include "Ellipse.h"

using namespace Shapes;

double Ellipse::get_perimeter() const {
    // approximation by Ramanujan
    double lambda2 = std::pow((a_axis - b_axis) / (a_axis + b_axis), 2);
    return PI * (a_axis + b_axis) * (1 + 3 * lambda2 / (10 + std::sqrt(4 - 3 * lambda2)));
}

double Ellipse::get_area() const {
    return PI * a_axis * b_axis;
}

void Ellipse::print_info() const {
    std::cout << "Ellipse shape with:\nmajor axis = " << std::max(a_axis, b_axis) << "\nminor axis = "
              << std::min(a_axis, b_axis) << "\ncenter point: " << center[0] << " " << center[1] << std::endl;
}

double Ellipse::get_a_axis() const {
    return a_axis;
}

double Ellipse::get_b_axis() const {
    return b_axis;
}

std::array<double, 2> Ellipse::get_center() const {
    return center;
}
