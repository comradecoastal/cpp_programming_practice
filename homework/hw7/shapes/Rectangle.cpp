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
    side_a = a;
    side_b = b;
    update_shape();
}

void Shapes::Rectangle::set_origin(std::array<double, 2> orig) {
    origin = orig;
    update_shape();
}

void Shapes::Rectangle::set_a_side(double a) {
    side_a = a;
    update_shape();
}

void Shapes::Rectangle::set_b_side(double b) {
    side_b = b;
    update_shape();
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

void Shapes::Rectangle::update_shape() {
    Polygon::set_vertices(
            {origin, {origin[0] + side_a, origin[1]}, {origin[0] + side_a, origin[1] + side_b},
             {origin[0], origin[1] + side_b}});
}




