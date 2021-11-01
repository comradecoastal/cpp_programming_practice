//
// Created by coastal on 10/28/21.
//

#ifndef DEFAULT_CIRCLE_H
#define DEFAULT_CIRCLE_H

#include "Ellipse.h"

class Shapes::Circle : public Ellipse {
public:
    Circle() = default;

    explicit Circle(double diameter) : Ellipse(diameter, diameter) {}

    Circle(double diameter, std::array<double, 2> center) : Ellipse(diameter, diameter, center) {}

    // required virtual methods
    double get_perimeter() const override;

    double get_area() const override;

    void print_info() const override;

    // getters
    double get_diameter() const;

    std::array<double, 2> get_center() const override;

    // setters
    void set_diameter(double d);

    void set_center(std::array<double, 2> c) override;

};


#endif //DEFAULT_CIRCLE_H
