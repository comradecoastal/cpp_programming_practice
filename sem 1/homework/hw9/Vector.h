#ifndef DEFAULT_VECTOR_H
#define DEFAULT_VECTOR_H

#include <cmath>
#include <iostream>
#include <vector>

template<typename T>
class Vector {
public:

    // constructors
    Vector(unsigned new_dim, std::vector<T> &new_components) : dim(new_dim),
                                                               components(std::move(new_components)) {
        components.resize(dim);
    }

    explicit Vector(unsigned int new_dim) : dim(new_dim), components(std::vector<double>(new_dim)) {}

    explicit Vector(std::vector<T> new_components) : dim(new_components.size()),
                                                     components(std::move(new_components)) {}

    Vector() = default;

    // getters
    unsigned get_dim() const;

    const std::vector<T> &get_components() const;

    // setters
    void set_components(const std::vector<T> &components);

    void set_dim(unsigned int dim);

    //methods
    double norm();

    //operators
    // times number
    friend Vector<T> operator*(Vector<T> &a, T lambda) {
        Vector out(a);
        for (auto &elem: out.components) {
            elem *= lambda;
        }
        return out;
    }

    // times number
    friend Vector<T> operator*(T lambda, Vector<T> &a) {
        return a * lambda;
    }

    // addition
    friend Vector<T> operator+(Vector<T> &a, Vector<T> &b) {
        Vector out(a);
        for (auto i = 0u; i < a.dim; i++) {
            out.components.at(i) += b.components.at(i);
        }
        return out;
    }

    // subtraction
    friend Vector<T> operator-(Vector<T> &a, Vector<T> &b) {
        Vector out(a);
        for (auto i = 0u; i < a.dim; i++) {
            out.components.at(i) -= b.components.at(i);
        }
        return out;
    }

    // scalar product
    friend T operator*(Vector<T> &a, Vector<T> &b) {
        T out = 0;
        for (auto i = 0u; i < a.dim; i++) {
            out += a.components.at(i) * b.components.at(i);
        }
        return out;
    }

    // output
    friend std::ostream &operator<<(std::ostream &out, Vector<T> a) {
        out << '[';
        for (auto i = 0u; i < a.dim - 1; i++) {
            out << a.components.at(i) << ", ";
        }
        out << a.components.at(a.dim - 1) << ']';
        return out;
    }

    // input
    friend std::istream &operator>>(std::istream &in, Vector<T> &a) {
        in >> a.dim;
        a.set_dim(a.dim);
        for (auto i = 0u; i < a.dim; i++) {
            in >> a.components.at(i);
        }
        return in;
    }

private:
    unsigned dim;
    std::vector<T> components;
};


template<typename T>
void Vector<T>::set_dim(unsigned int new_dim) {
    dim = new_dim;
    components.resize(dim);
}

template<typename T>
const std::vector<T> &Vector<T>::get_components() const {
    return components;
}

template<typename T>
void Vector<T>::set_components(const std::vector<T> &new_components) {
    Vector::components = new_components;
    dim = components.size();
}

template<typename T>
double Vector<T>::norm() {
    /**
     * returns norm of vector
     */
    double output = 0;
    for (T elem: components) {
        output += elem * elem;
    }
    return std::sqrt(output);
}

template<typename T>
unsigned Vector<T>::get_dim() const {
    return dim;
}



#endif //DEFAULT_VECTOR_H
