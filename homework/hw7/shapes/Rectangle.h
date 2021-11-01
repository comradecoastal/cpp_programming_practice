//
// Created by coastal on 10/30/21.
//

#ifndef DEFAULT_RECTANGLE_H
#define DEFAULT_RECTANGLE_H

#include "Polygon.h"

class Shapes::Rectangle : public Polygon {
public:
    Rectangle() : side_a(0), side_b(0), origin({0, 0}), Polygon(4) {}

    // side a and b given
    Rectangle(double a, double b) : side_a(a), side_b(b), origin({0, 0}), Polygon(4) {
        Polygon::set_vertices(
                {origin, {origin[0] + a, origin[1]}, {origin[0] + a, origin[1] + b}, {origin[0], origin[1] + b}});
    }

    // side a, b and origin given
    Rectangle(double a, double b, std::array<double, 2> orig) : side_a(a), side_b(b), origin(orig),
                                                                Polygon(4) {
        Polygon::set_vertices(
                {origin, {origin[0] + a, origin[1]}, {origin[0] + a, origin[1] + b}, {origin[0], origin[1] + b}});
    }

    // required virtual methods
    double get_area() const override;

    double get_perimeter() const override;

    void print_info() const override;

    // getters
    const std::vector<std::array<double, 2>> &get_vertices() const override;

    double get_a_side() const;

    double get_b_side() const;

    std::array<double, 2> get_sides() const;

    virtual std::array<double, 2> get_origin() const;

    // setters
    void set_a_side(double a);

    void set_b_side(double b);

    void set_sides(double a, double b);

    virtual void set_origin(std::array<double, 2> orig);

private:
    void update_shape();

    double side_a, side_b;
    std::array<double, 2> origin; // lower left corner
};


#endif //DEFAULT_RECTANGLE_H
