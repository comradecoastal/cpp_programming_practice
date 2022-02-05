#include "TestClassB.h"
#include <iostream>

int main() {
    // undefined reference error
    TestClassB test;
    test.set_a(5);

    std::cout << test.get_a() << std::endl;
}


