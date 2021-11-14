#include "Vector.h"
#include <iostream>

int main() {
    Vector<int> a({1, 2, 3});
    Vector<int> b({4, 4, 4});
    Vector<double> c({0.1, 0.2, 0.3});
    Vector<double> d({0.4, 0.5, 0.6});
    std::cout << a.get_dim() << ", " << c.get_dim() << std::endl;
    std::cout << a << " " << a.norm() <<  ", " << c << " " << c.norm() << std::endl;
    std::cout << a + b << ", " << a * b << "; " << c + d << ", " << c * d << std::endl;

    std::cout << "Enter vector a(int):";
    std::cin >> a;
    std::cout << "a = " << a << std::endl;

    std::cout << "Enter vector c(double):";
    std::cin >> c;
    std::cout << "c = " << c << std::endl;
}