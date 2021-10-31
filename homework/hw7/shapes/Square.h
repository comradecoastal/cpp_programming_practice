//
// Created by coastal on 10/31/21.
//

#ifndef DEFAULT_SQUARE_H
#define DEFAULT_SQUARE_H

#include "Rectangle.h"

class Shapes::Square: Rectangle {
public:
    Square(): Rectangle() {}
    Square(double side): Rectangle(side, side) {}
    Square(double side, std::array<double, 2> orig): Rectangle(side, side, orig) {}

    const std::vector<std::array<double, 2>> & get_vertices() const override;
    double get_perimeter() const override;
    double get_area() const override;
    void print_info() const override;

    double get_side() const;
    void set_side(double side);

    std::array<double, 2> get_origin() const override;
};


#endif //DEFAULT_SQUARE_H
