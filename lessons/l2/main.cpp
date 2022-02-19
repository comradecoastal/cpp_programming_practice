#include <iostream>
#include <list>

int main() {
    std::list<int> numbers {-1, 2, -3, 4, -5};
    std::list<int> other_numbers {100, -200, 300, -400, 500};

    numbers.splice(std::next(numbers.begin(), 2), other_numbers, other_numbers.begin(), other_numbers.end());

    numbers.sort([](auto lhs, auto rhs){return abs(lhs) < abs(rhs);});
    for (auto number: numbers) {
        std::cout << number << ' ';
    }

    std::cout << std::endl;
}
