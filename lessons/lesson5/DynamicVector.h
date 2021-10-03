//
// Created by coastal on 10/2/21.
//

#ifndef DEFAULT_DYNAMICVECTOR_H
#define DEFAULT_DYNAMICVECTOR_H

#endif //DEFAULT_DYNAMICVECTOR_H

#include <iostream>
#include <vector>

class DynamicVector {
public:
    DynamicVector(unsigned dimension);

    const unsigned* get_dimension() const {
        return dimension;
    }

    const double* get_components() const {
        return components;
    }

    void set_components(const std::vector<double>& components) {
        *(this->dimension) = components.size();
        double* new_components = new double[components.size()];
        for(auto i = 0u; i < components.size(); i++) {
            new_components[i] = components[i];
        }
        delete[] this -> components;
        this->components = new_components;
    }

    friend std::ostream& operator << (std::ostream& out, const DynamicVector& v);
    friend std::istream& operator >> (std::istream& in, DynamicVector& v);

    ~DynamicVector() {
        delete dimension;
        delete[] components;
    }

private:
    double* components;
    unsigned* dimension;
};


