#include <iostream>
#include <functional>

template<typename T, typename... Types>
T *pointer_creator(Types ... args) {
    auto out = new T(args...);
    return out;
}


int main() {
    auto a = pointer_creator<double>(5);
    std::cout << (*a) << std::endl;
    delete a;
    std::cout << (*a) << std::endl;
    auto b = pointer_creator<std::string>("homo sapiens");
    std::cout << (*b) << std::endl;
    for (auto i = 0u; i < 10; i++) {
        (*b) += (*b);
    }
    std::cout << (*b) << std::endl;
    delete b;
    // выходит за доступную память
//    std::cout << (*b) << std::endl;
    std::cout << "abacaba" << std::endl;
}

