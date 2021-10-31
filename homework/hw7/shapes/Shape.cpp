//
// Created by coastal on 10/27/21.
//

#include "Shape.h"

using namespace Shapes;

double Shape::get_perimeter() const {
    /**
     * Method supposed to return perimeter of a shape
     */
    return 0;
}

double Shape::get_area() const {
    /**
     * Method supposed to return the area of a shape
     */
    return 0;
}

void Shape::print_info() const {
    /**
     * Method supposed to print info about the file to cout
     */
    std::cout << "empty shape class" << std::endl;
}

std::ostream &operator<<(std::ostream & out, const Shape& shape) {
    out << "empty shape class";
    return out;
}

