#include <iostream>

int main() {
    // this seems trivial

    int x, y;
//    x = 5;
//    y = 7;
    std::cin >> x;
    std::cin >> y;

    std::cout << "x = " << x << ", y = " << y << std::endl;
    y += x;
    x = y - x;
    y -= x;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    return 0;
}