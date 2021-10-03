#include "DynamicVector.h"

DynamicVector::DynamicVector(unsigned int dimension) {

    this->dimension = new unsigned(dimension);
    this->components = new double[dimension];
    for (auto i = 0u; i < dimension; i++) {
        this->components[i] = 0.;
    }
}

std::ostream &operator<<(std::ostream &out, const DynamicVector &v) {
    out << "Dimension is: " << *v.dimension << " Components are: ";
    for (auto i = 0u; i < *v.dimension; i++) {
        out << v.components[i] << ", ";
    }
    out << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, DynamicVector &v) {
    for (auto i = 0u; i < *v.dimension; i++) {
        in >> v.components[i];
    }
    return in;
}
