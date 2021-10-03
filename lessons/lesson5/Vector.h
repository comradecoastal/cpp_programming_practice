//
// Created by coastal on 10/2/21.
//

#ifndef DEFAULT_VECTOR_H
#define DEFAULT_VECTOR_H

#endif //DEFAULT_VECTOR_H


class DynamicVector {
public:
    DynamicVector(const std::vector<double> &new_components, unsigned new_dimension) :
            components(new_components), dimension(new_dimension) {}

    DynamicVector(const std::vector<double> &new_components) : components(new_components), dimension(new_components.size()) {}

    DynamicVector(unsigned int new_dimension) : components(new_dimension), dimension(new_dimension) {}

    DynamicVector() = default;

    // copy-constructor
    DynamicVector(const DynamicVector& another): components(another.components), dimension(another.dimension) {}

    // Getters and setters

    const std::vector<double> &get_components() const {
        return components;
    }

    unsigned int get_dimension() const {
        return dimension;
    }

    void set_dimension(unsigned int new_dimension) {
        new_dimension = new_dimension;
        components.resize(new_dimension);
    }

    void set_components(const std::vector<double> &new_components) {
        components = new_components;
        dimension = new_components.size();
    }

private:
    std::vector<double> components;
    unsigned dimension{};
};
