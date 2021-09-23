#include <functional>
#include <iostream>
#include <vector>

double calculate(double a, double b, const std::function<double(double, double)> &f) {
    /**
     * Function takes numbers a and b, and function f, returns result of f(a, b)
     */
    return f(a, b);
}

int main() {

    double a, b;
    // vector of functions
    std::vector<std::function<double(double, double)>> functions = {
            [](double a, double b) { return a + b; },
            [](double a, double b) { return a - b; },
            [](double a, double b) { return a * b; },
            [](double a, double b) { return a / b; },
            [](double a, double b) { return a * a * a - b * b; }
    };
    std::cout << "Enter a and b : ";
    std::cin >> a >> b;

    for (auto &f: functions) {
        std::cout << calculate(a, b, f) << std::endl;
    }

    return 0;
}
