#include <iostream>
#include <set>
#include <vector>

int main() {
    std::vector<int> numbers{6, 23, -43, 32, -54};
    auto it = numbers.begin();
    std::cout << *it++ << std::endl;
    std::cout << *it << std::endl;

    auto end_it = numbers.end();
    auto last_it = std::prev(end_it);
    std::cout << *end_it << std::endl;


}

