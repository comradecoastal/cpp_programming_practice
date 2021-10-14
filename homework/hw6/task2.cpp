#include <iostream>
#include "Fraction.h"

int main() {
    Fraction a(1, 4);
    Fraction b(3, 4);

    std::cout << R"(Enter two fractions ("23/4", "-2/7"): )";
    std::cin >> a >> b;

    Fraction c = a;
    c = c + 2; // implicit conversion
    std::cout << a << " " << b << " " << c << std::endl;

    std::cout << a + b << " " << a - b << " " << b - a << " " << a * b <<
              " " << a / b << " " << b / a << std::endl;
    std::cout << a++ << " " << a << " " << ++b << " " << b << std::endl;
    std::cout << a-- << " " << a << " " << --b << " " << b << std::endl;

}