#include <iostream>

int main() {
    int b = 0, i = 0;

    for (auto j = 0u; j < 10; j++) {
        std::cout << i++ << " " << ++b << std::endl;
    }
    std::cout << i << " " << b << std::endl;
}
