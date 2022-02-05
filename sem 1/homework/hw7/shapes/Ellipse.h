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
            center({0, 0}), a_axis(a), b_axis(b) {}

    Ellipse(double a, double b, std::array<double, 2> center) :
            center(center), a_axis(a), b_axis(b) {}

    // required virtual methods
    double get_perimeter() const override;

    double get_area() const override;

    void print_info() const override;

    // getters
    double get_a_axis() const;

    double get_b_axis() const;

    virtual std::array<double, 2> get_center() const; // override in Circle

    //setters
    void set_a_axis(double a);

    void set_b_axis(double b);

    void set_axes(double a, double b);

    virtual void set_center(std::array<double, 2> c); // override in Circle

private:
    std::array<double, 2> center; // center of elliplse
    double a_axis; // first axis
    double b_axis; // second axis
};


#endif //DEFAULT_ELLIPSE_H
