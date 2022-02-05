//
// Created by coastal on 10/31/21.
//

#ifndef DEFAULT_SQUARE_H
#define DEFAULT_SQUARE_H

#include "Rectangle.h"

class Shapes::Square : public Rectangle {
public:
    Square() : Rectangle() {}

    explicit Square(double side) : Rectangle(side, side) {}

    Square(double side, std::array<double, 2> orig) : Rectangle(side, side, orig) {}

    // required virtual methods
    double get_perimeter() const override;

    double get_area() const override;

    void print_info() const override;

    // getters
    const std::vector<std::array<double, 2>> &get_vertices() const override;

    double get_side() const;

    std::array<double, 2> get_origin() const override;


    // setters
    void set_side(double side);

    void set_origin(std::array<double, 2> orig) override;


};


#endif //DEFAULT_SQUARE_H
