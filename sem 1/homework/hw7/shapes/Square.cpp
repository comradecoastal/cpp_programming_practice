//
// Created by coastal on 10/31/21.
//

#include "Square.h"

const std::vector<std::array<double, 2>> &Shapes::Square::get_vertices() const {
    return Rectangle::get_vertices();
}

double Shapes::Square::get_perimeter() const {
    return Rectangle::get_perimeter();
}

double Shapes::Square::get_area() const {
    return Rectangle::get_area();
}

void Shapes::Square::print_info() const {
    std::cout << "Square shape with:\nside = " << get_side() << "\n";
    std::cout << "With origin located at point (x, y): " << get_origin()[0] << ' ' << get_origin()[1] << std::endl;
}

double Shapes::Square::get_side() const {
    return Rectangle::get_a_side();
}

void Shapes::Square::set_side(double side) {
    Rectangle::set_sides(side, side);
}

std::array<double, 2> Shapes::Square::get_origin() const {
    return Rectangle::get_origin();
}

void Shapes::Square::set_origin(std::array<double, 2> orig) {
    Rectangle::set_origin(orig);
}
