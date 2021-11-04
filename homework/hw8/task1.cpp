#include <iostream>
#include "Fraction.h"

int main() {
    Fraction a(1, 4);
    Fraction b(3, 4);

    std::cout << R"(Enter two fractions ("23/4", "-2/7"): )";

    try {
        // if you enter 1/0 error is thrown
        std::cin >> a >> b;
        std::cout << a << " = " << static_cast<double>(a) << ", " << b << " = " << double(b) << std::endl;

    } catch (ZeroDivisionError& err) {
        std::cerr << err.what() << std::endl;
    }


    try {
        a/b;
    } catch (ZeroDivisionError& err) {
        std::cerr << "Can't divide" << std::endl;
    }

    // end program with error
    Fraction c(2, 0);

//    Fraction c = a;
//    c = c + 2; // implicit conversion
//    std::cout << a << " " << b << " " << c << std::endl;
//
//    std::cout << a + b << " " << a - b << " " << b - a << " " << a * b <<
//              " " << a / b << " " << b / a << std::endl;
//    std::cout << a++ << " " << a << " " << ++b << " " << b << std::endl;
//    std::cout << a-- << " " << a << " " << --b << " " << b << std::endl;

}