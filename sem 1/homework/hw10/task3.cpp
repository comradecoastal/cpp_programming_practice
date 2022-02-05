#include <iostream>

// first
template<typename T, typename... Types>
int recursive_size_calculator(T &first, Types &... args) {
    int out = 0;
    out += sizeof(first);
    if constexpr(sizeof...(args) > 0) {
        out += recursive_size_calculator(args...);
    }
    return out;
}

// with operator
template<typename ... Types>
int size_calculator(Types &... args) {
    return (... + sizeof(args));
}

int main() {
    double fizz = 13.37;
    std::string buzz = "buzz";
    int ints[] = {1, 2, 3, 4};
    std::cout << sizeof(fizz) + sizeof(buzz) + sizeof(ints) << std::endl;
    std::cout << recursive_size_calculator(fizz, buzz, ints) << std::endl;
    std::cout << size_calculator(fizz, buzz, ints) << std::endl;
}
