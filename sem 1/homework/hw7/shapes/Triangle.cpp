//
// Created by coastal on 10/31/21.
//

#include "Triangle.h"

double Shapes::Triangle::get_area() const {
    return Polygon::get_area();
}

double Shapes::Triangle::get_perimeter() const {
    return Polygon::get_perimeter();
}

void Shapes::Triangle::print_info() const {
    const std::vector<std::array<double, 2>> *vert = &get_vertices();
    std::cout << "Triangle shape with:\nsides:" << Shapes::length(vert->at(0), vert->at(1)) << ", "
              << Shapes::length(vert->at(1), vert->at(2)) << ", "
              << Shapes::length(vert->at(2), vert->at(0)) << "\nvertices (x, y): "
              << vert->at(0).at(0) << ' ' << vert->at(0).at(1) << ", "
              << vert->at(1).at(0) << ' ' << vert->at(1).at(1) << ", "
              << vert->at(2).at(0) << ' ' << vert->at(2).at(1) << std::endl;
}

const std::vector<std::array<double, 2>> &Shapes::Triangle::get_vertices() const {
    return Polygon::get_vertices();
}

std::array<double, 3> Shapes::Triangle::get_sides() const {
    std::array<double, 3> sides{};
    const std::vector<std::array<double, 2>> *vert = &get_vertices();
    for (auto i = 0u; i < 3; i++) {
        sides.at(i) = length(vert->at(i), vert->at((i + 1) % 3));
    }
    return sides;
}

void Shapes::Triangle::set_vertices(const std::vector<std::array<double, 2>> &vert) {
    if (vert.size() == 3)
        Polygon::set_vertices(vert);
}
