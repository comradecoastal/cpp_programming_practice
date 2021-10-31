//
// Created by coastal on 10/30/21.
//

#ifndef DEFAULT_RECTANGLE_H
#define DEFAULT_RECTANGLE_H

#include "Polygon.h"

class Shapes::Rectangle : Polygon {
public:
    Rectangle(): Polygon(4) {}

    // side a and b given
    Rectangle(double a, double b) : side_a(a), side_b(b), side_a_tilt(0), origin({0, 0}), Polygon(4) {
        Polygon::set_vertices(
                {origin, {origin[0] + a, origin[1]}, {origin[0] + a, origin[1] + b}, {origin[0], origin[1] + b}});
    }

    // side a, b and origin given
    Rectangle(double a, double b, std::array<double, 2> orig) : side_a(a), side_b(b), side_a_tilt(0), origin(orig),
                                                                Polygon(4) {
        Polygon::set_vertices(
                {origin, {origin[0] + a, origin[1]}, {origin[0] + a, origin[1] + b}, {origin[0], origin[1] + b}});
    }

    double get_area() const override;
    double get_perimeter() const override;
    void print_info() const override;

    const std::vector<std::array<double, 2>> & get_vertices() const override;

    double get_a_side() const;
    double get_b_side() const;
    std::array<double, 2> get_sides() const;

    virtual std::array<double, 2> get_origin() const;

    void set_sides(double a, double b);
    void set_sides(std::array<double, 2>);

private:
    double side_a, side_b, side_a_tilt;
    std::array<double, 2> origin;
};


#endif //DEFAULT_RECTANGLE_H
