//
// Created by coastal on 10/27/21.
//

#include "Polygon.h"

using namespace Shapes;

double Polygon::get_perimeter() const{
    double perimeter = 0;
    for (auto i = 0u; i < (dimension - 1); i++) {
        perimeter += length(vertices[i], vertices[i + 1]);
    }
    perimeter += length(vertices[0], vertices[dimension - 1]);
    return perimeter;
}

double Polygon::get_area() const {
    double area = 0;
    // shoelace formula
    for (auto i = 0u; i < (dimension - 1); i++) {
        area += vertices[i][0] * vertices[i + 1][1] - vertices[i + 1][0] * vertices[i][1];
    }
    area += vertices[dimension - 1][0] * vertices[0][1] - vertices[0][0] * vertices[dimension - 1][1];
    area = std::abs(area) / 2;
    return area;
}

void Polygon::print_info() const {
    std::cout << "Polygon shape with following data:\nNumber of vertices = " << dimension << '\n';
    std::cout << "Coordinates of vertices (x, y):\n";
    for (auto point : vertices) {
        std::cout << point[0] << ' ' << point[1] << '\n';
    }
}

const std::vector<std::array<double, 2>>& Polygon::get_vertices() const {
    return vertices;
}

void Polygon::set_vertices(std::vector<std::array<double, 2>> vert) {
    vertices = std::move(vert);
    dimension = vertices.size();
}

