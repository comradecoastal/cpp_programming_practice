#include <iostream>
#include "SmartDoublePtr.h"

int main() {
    SmartDoublePtr a(2);
//    SmartDoublePtr f(12.34);

    double b = 9.9;
    SmartDoublePtr c(&b);


    SmartDoublePtr e(std::move(a));
    SmartDoublePtr f(12.34);
    f = std::move(c);

    std::cout << e << std::endl;
    std::cout << a << " " << c << " " << e << " "  << f << std::endl;
    std::cout << e.getValue() << " " << *e << std::endl;

    std::cout << e << " " << *e << std::endl;
    *e = 13;
    std::cout << e << " " << *e << std::endl;
}
