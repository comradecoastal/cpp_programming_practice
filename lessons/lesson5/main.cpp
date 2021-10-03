#include <iostream>
#include <vector>
#include "DynamicVector.h"
#include "Vector.h"

int main() {
    DynamicVector v(3);
    v.set_components({1, 2, 3});
    std::cin >> v;

    std::cout << v;

}