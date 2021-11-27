#include <functional>
#include <iostream>

// use function pointer
//template<typename T, typename... Types>
//void function_caller(T(*f)(Types...), Types ... args) {
//    std::cout << (*f)(args...) << std::endl;
//}

// use std::function as function object
// это больше походит на ООП
template<typename T, typename... Types>
void function_caller(std::function<T(Types...)> &f, Types ... args) {
    std::cout << f(args...) << std::endl;
}

int discriminant(int a, int b, int c) {
    return b * b - 4 * a * b;
}

double square(double a) {
    return a * a;
}

std::string multiply_sting(const std::string &abacaba, int n) {
    std::string out;
    for (auto i = 0u; i < n; i++) {
        out += abacaba;
    }
    return out;
}

std::string return_string(const std::string &a) {
    std::string out;
    out += a;
    return out;
}

int main() {
    std::function<int(int, int, int)> first_function = &discriminant;
    std::function<double(double)> second_function = &square;
    std::function<std::string(const std::string &)> third_function = &return_string;
    std::function<std::string(const std::string &, int)> fourth_function = &multiply_sting;

//    int (*first_function)(int, int, int) = &discriminant;
//    double (*second_function)(double ) = &square;
//    std::string (*third_function)(const std::string&) = &return_string;

    function_caller(first_function, 1, 1, 1);
    function_caller(second_function, 5.5);
    function_caller<std::string, const std::string &>(third_function, "bruh");
    function_caller<std::string, const std::string &, int>(fourth_function, "bruh", 4);


}
