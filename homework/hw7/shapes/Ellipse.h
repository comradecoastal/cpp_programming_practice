//
// Created by coastal on 10/28/21.
//

#ifndef DEFAULT_ELLIPSE_H
#define DEFAULT_ELLIPSE_H

#include "Shape.h"

class Shapes::Ellipse : public Shape {
public:
    Ellipse() = default;

    Ellipse(double a, double b) :
            center({0, 0}), a_axis(a), b_axis(b), a_axis_tilt(0) {}

    Ellipse(double a, double b, std::array<double, 2> center) :
            center(center), a_axis(a), b_axis(b), a_axis_tilt(0) {}

    Ellipse(double a, double b, std::array<double, 2> center, double c) :
            center(center), a_axis(a), b_axis(b), a_axis_tilt(c) {}

    double get_perimeter() const override;
    double get_area() const override;
    void print_info() const override;

    double get_a_axis() const;
    double get_b_axis() const;
    std::array<double, 2> get_center() const;

private:
    std::array<double, 2> center;
    double a_axis;
    double b_axis;
    double a_axis_tilt;
};


#endif //DEFAULT_ELLIPSE_H
