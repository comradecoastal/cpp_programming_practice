#include <bitset>
#include <iomanip>
#include <iostream>

int main() {
    int x = 0b1010;
    std::cout << x << std::endl;

    std::bitset<4> bools(0b1010);
    std::cout << bools << std::endl;
    std::cout << bools[0] << std::endl;
    std::cout << bools[1] << std::endl;
    std::cout << bools[2] << std::endl;
    std::cout << bools[3] << std::endl;
    std::cout << (bools & std::bitset<4>(0b10)) << std::endl;


    int a = 5, b = 6, c;
    char op;
    std::cin >> op;

    switch(op) {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        default:
            c = 0;
    }

    std::cout << c << std::endl;

}

