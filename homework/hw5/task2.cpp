#include "Vector.h"

int main() {
    Vector a({1, 2, 3});
    Vector b({4, 5, 6});
    double c = 11.4;

    Vector d;
    std::cin >> d;
    std::cout << d << " " << d.norm() << std::endl;

    std::cout << a << b << a * c << a * b << a + b << a - b << std::endl;

    return 0;
}