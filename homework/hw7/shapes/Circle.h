//
// Created by coastal on 10/28/21.
//

#ifndef DEFAULT_CIRCLE_H
#define DEFAULT_CIRCLE_H

#include "Ellipse.h"

class Shapes::Circle : Ellipse {
public:
    Circle() = default;

    Circle(double diameter) : Ellipse(diameter, diameter) {}

    Circle(double diameter, std::array<double, 2> center): Ellipse(diameter, diameter, center) {}

    double get_perimeter() const override;
    double get_area() const override;
    void print_info() const override;

};


#endif //DEFAULT_CIRCLE_H
