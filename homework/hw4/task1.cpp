#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

// vector structure
struct Vector {
    /**
     * Vector from linear algebra with defined operations for:
     * multiplication by number
     * addition
     * subtraction
     * scalar product
     * norm as .norm() function
     */
    std::vector<double> components;
    unsigned dim;

    explicit Vector(unsigned a = 0, std::vector<double> b = {}) {
        /**
         * @param a dimension of vector
         * @param b vector
         */
        dim = a;
        components = std::move(b);
        if (components.size() != dim) {
            components = std::vector<double>(dim, 0);
        }
    }

    double norm() {
        /**
         * returns norm of vector
         */
        double output = 0;
        for (double elem : components) {
            output += elem * elem;
        }
        return std::sqrt(output);
    }
};

// multiplication by number
Vector operator * (const Vector& a, double lambda) {
    Vector output(a.dim, a.components);
    for (auto& elem : output.components){
        elem *= lambda;
    }
    return output;
}

// reverse multiplication by number
Vector operator * (double lambda, const Vector& a) {
    return a * lambda;
}

// addition
Vector operator + (const Vector& a, const Vector& b) {
    Vector output(a.dim, a.components);
    for (auto i = 0; i < a.dim; i++) {
        output.components.at(i) += b.components.at(i);
    }
    return output;
}

// subtraction
Vector operator - (const Vector& a, const Vector& b) {
    Vector output(a.dim, a.components);
    for (auto i = 0; i < a.dim; i++) {
        output.components.at(i) -= b.components.at(i);
    }
    return output;
}

// negative
Vector operator - (const Vector& a) {
    Vector output(a.dim, a.components);
    for (auto i = 0; i < a.dim; i++) {
        output.components.at(i) *= -1;
    }
    return output;
}

// scalar product
double operator * (const Vector& a, const Vector& b) {
    double output = 0;
    for (auto i = 0; i < a.dim; i++) {
        output += a.components.at(i) * b.components.at(i);
    }
    return output;
}

// ostream formatting
std::ostream& operator<<(std::ostream& ostr, const Vector& a) {
    ostr << '[';
    for(auto i = 0; i < a.dim - 1; i++) {
        ostr << a.components.at(i) << ", ";
    }
    ostr << a.components.at(a.dim - 1) << ']';
    return ostr;
}

int main() {
    // define vectors
    Vector a(4, {1, 1, 1, 1});
    Vector b(4, {1, 2, 3, 4});
    Vector c(4);
    Vector d(4, {1, 2, 3});

    std::cout << c << ' ' << d << std::endl; // constructed as vectors of 0;

    c = a - b;
    d = c + a;

    std::cout << -b << ' ' << c << ' ' << d << std::endl; // + and - operators
    std::cout << a * b << ' ' << c * d << std::endl; // scalar product

    a = a * 2; // multiplication by number
    b = 1.5 * b;

    std::cout << a.norm() << ' ' << b.norm() << ' ' << c.norm() << ' ' << d.norm() << std::endl; // norm of vector
    std::cout << a << ' ' << b << ' ' <<  c << ' ' << d << std::endl;

    return 0;
}
