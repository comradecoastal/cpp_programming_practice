//
// Created by coastal on 10/27/21.
//

#ifndef DEFAULT_POLYGON_H
#define DEFAULT_POLYGON_H

#include "Shape.h"

class Shapes::Polygon: public Shape{
public:
    Polygon() = default;
    // if all coordinates are given
    explicit Polygon(std::vector<std::array<double, 2>> vert): vertices(std::move(vert)), dimension(vertices.size()) {}
    // if only number is given
    explicit Polygon(unsigned dim): dimension(dim) {
        vertices.resize(dimension);
    }

    double get_perimeter() const override;
    double get_area() const override;
    void print_info() const override;


    virtual const std::vector<std::array<double, 2>>& get_vertices() const;
    void set_vertices(std::vector<std::array<double, 2>> vert);

private:
    std::vector<std::array<double, 2>> vertices;
    unsigned dimension;
};


#endif //DEFAULT_POLYGON_H
