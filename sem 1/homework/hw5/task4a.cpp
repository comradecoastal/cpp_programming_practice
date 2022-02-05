#include "TestClassA.h"
#include <iostream>

int main() {
    // redefinition error
    TestClassA test;
    test.set_a(5);

    std::cout << test.get_a() << std::endl;
}

