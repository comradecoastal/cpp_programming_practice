//
// Created by coastal on 10/27/21.
//

#ifndef DEFAULT_POLYGON_H
#define DEFAULT_POLYGON_H

#include "Shape.h"

class Shapes::Polygon : public Shape {
public:
    Polygon() = default;

    // if all coordinates are given
    explicit Polygon(std::vector<std::array<double, 2>> vert) :
            vertices(std::move(vert)), dimension(vertices.size()) {}

    // if only dimension number is given
    explicit Polygon(unsigned dim) : dimension(dim) {
        vertices.resize(dimension);
    }

    // required virtual methods
    double get_perimeter() const override;

    double get_area() const override;

    void print_info() const override;

    // getters
    virtual const std::vector<std::array<double, 2>> &get_vertices() const;

    unsigned get_dimension()  const;

    // setters
    void set_vertices(std::vector<std::array<double, 2>> vert);

    void set_vertex(unsigned pos, std::array<double, 2> vert); // set single vertex

    void set_dimension(unsigned dim);

private:
    std::vector<std::array<double, 2>> vertices;
    unsigned dimension;
};


#endif //DEFAULT_POLYGON_H
