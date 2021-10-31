//
// Created by coastal on 10/30/21.
//

#include "Rectangle.h"

double Shapes::Rectangle::get_area() const {
    return Polygon::get_area();
}

double Shapes::Rectangle::get_perimeter() const {
    return Polygon::get_perimeter();
}

void Shapes::Rectangle::print_info() const {
    std::cout << "Rectangle shape with sides:\na = " << side_a << ", b = " << side_b << '\n';
    std::cout << "With origin located at point (x, y): " << origin[0] << ' ' << origin[1] << std::endl;
}

const std::vector<std::array<double, 2>> &Shapes::Rectangle::get_vertices() const {
    return Polygon::get_vertices();
}

void Shapes::Rectangle::set_sides(double a, double b) {
    Polygon::set_vertices(
            {origin, {origin[0] + a, origin[1]}, {origin[0] + a, origin[1] + b}, {origin[0], origin[1] + b}});
}

void Shapes::Rectangle::set_sides(std::array<double, 2> sides) {
    set_sides(sides[0], sides[1]);
}

double Shapes::Rectangle::get_a_side() const {
    return side_a;
}

double Shapes::Rectangle::get_b_side() const {
    return side_b;
}

std::array<double, 2> Shapes::Rectangle::get_sides() const {
    return {side_a, side_b};
}

std::array<double, 2> Shapes::Rectangle::get_origin() const {
    return origin;
}
