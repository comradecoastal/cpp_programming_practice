#include <cmath>
#include <iostream>
#include <vector>


int main() {
    const int AMOUNT_OF_NUMBERS = 30;
    std::vector<int> numbers;
    std::cout << "Size is " << numbers.size() << std::endl;
    for(auto i = 0; i < AMOUNT_OF_NUMBERS; i++) {
        numbers.push_back(static_cast<int>(std::pow(i, 3)));
//        std::cout << "Iteration #" << i << ", size is " << numbers.capacity() << std::endl;
    }

    for(auto num: numbers) {
        std::cout << num << std::endl;
    }
}
