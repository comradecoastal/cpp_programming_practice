//
// Created by coastal on 10/31/21.
//

#ifndef DEFAULT_TRIANGLE_H
#define DEFAULT_TRIANGLE_H

#include "Polygon.h"

class Shapes::Triangle : public Polygon {
public:
    Triangle() : Polygon(3) {}

    explicit Triangle(const std::vector<std::array<double, 2>> &vert) : Polygon(3) {
        if (vert.size() == 3)
            Polygon::set_vertices(vert);
    }

    // required virtual methods
    double get_area() const override;

    double get_perimeter() const override;

    void print_info() const override;

    // getters
    const std::vector<std::array<double, 2>> & get_vertices() const override;

    std::array<double, 3> get_sides() const;

    // setters
    void set_vertices(const std::vector<std::array<double, 2>> &vert);
};


#endif //DEFAULT_TRIANGLE_H
