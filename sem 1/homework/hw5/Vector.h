//
// Created by coastal on 10/3/21.
//

#ifndef DEFAULT_VECTOR_H
#define DEFAULT_VECTOR_H

#include <vector>
#include <iostream>

class Vector {
    /**
     * Vector from linear algebra with defined operations for:
     * multiplication by number
     * addition
     * subtraction
     * scalar product
     * norm as .norm() function
     */
public:

    // constructors
    Vector(unsigned, std::vector<double> &);

    explicit Vector(unsigned);

    explicit Vector(std::vector<double>);

    Vector() = default;

    // getters
    unsigned int get_dim() const;

    const std::vector<double> &get_components() const;

    // setters
    void set_components(const std::vector<double> &components);

    void set_dim(unsigned int dim);

    //methods
    double norm();

    //operators
    friend Vector operator*(Vector &, double); // multiplication by number

    friend Vector operator*(double, Vector &); // multiplication by number

    friend Vector operator+(Vector &, Vector &); // addition

    friend Vector operator-(Vector &, Vector &); // subtraction

    friend double operator*(Vector &, Vector &); // scalar product

    friend std::ostream &operator<<(std::ostream &, Vector); // output

    friend std::istream &operator>>(std::istream &, Vector &); // input

private:
    unsigned dim;
    std::vector<double> components;
};


#endif //DEFAULT_VECTOR_H
