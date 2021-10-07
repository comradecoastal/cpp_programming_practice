//
// Created by coastal on 10/3/21.
//

#include "Vector.h"
#include <vector>
#include <cmath>

Vector::Vector(unsigned int dim, std::vector<double> &components) {
    /**
     * @param dim dimension of vector
     * @param components vector
     */
    this->components = std::move(components);
    this->dim = dim;
}

Vector::Vector(unsigned int dim) {
    /**
     * @param dim dimension of vector
     */
    this->dim = dim;
    this->components = std::vector<double>(dim);
}

Vector::Vector(std::vector<double> components) {
    /**
     * @param components vector
     */
    this->components = std::move(components);
    this->dim = this->components.size();
}

unsigned int Vector::get_dim() const {
    return dim;
}

void Vector::set_dim(unsigned int dim) {
    this->dim = dim;
    this->components.resize(dim);
}

const std::vector<double> &Vector::get_components() const {
    return components;
}

void Vector::set_components(const std::vector<double> &components) {
    Vector::components = components;
    this->dim = components.size();
}

double Vector::norm() {
    /**
     * returns norm of vector
     */
    double output = 0;
    for (double elem: components) {
        output += elem * elem;
    }
    return std::sqrt(output);
}

Vector operator*(Vector &a, double lambda) {
    Vector out(a);
    for (auto &elem: out.components) {
        elem *= lambda;
    }
    return out;
}

Vector operator*(double lambda, Vector &a) {
    return a * lambda;
}

std::ostream &operator<<(std::ostream &out, Vector a) {
    out << '[';
    for (auto i = 0u; i < a.dim - 1; i++) {
        out << a.components.at(i) << ", ";
    }
    out << a.components.at(a.dim - 1) << ']';
    return out;
}

Vector operator+(Vector &a, Vector &b) {
    Vector out(a);
    for (auto i = 0u; i < a.dim; i++) {
        out.components.at(i) += b.components.at(i);
    }
    return out;
}

double operator*(Vector &a, Vector &b) {
    double out = 0;
    for (auto i = 0u; i < a.dim; i++) {
        out += a.components.at(i) * b.components.at(i);
    }
    return out;
}

std::istream &operator>>(std::istream &in, Vector &a) {
    in >> a.dim;
    a.set_dim(a.dim);
    for (auto i = 0u; i < a.dim; i++) {
        in >> a.components.at(i);
    }
    return in;
}

Vector operator-(Vector &a, Vector &b) {
    Vector out(a);
    for (auto i = 0u; i < a.dim; i++) {
        out.components.at(i) -= b.components.at(i);
    }
    return out;
}


