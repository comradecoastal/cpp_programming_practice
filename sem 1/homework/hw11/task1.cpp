#include <iostream>
#include <cmath>

// рекурсивное возведение числа в натуральную степень
constexpr double fast_exp(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent % 2 == 0) {
        return fast_exp(base * base, exponent / 2);
    } else {
        return base * fast_exp(base * base, (exponent - 1) / 2);
    }
}

// рекурсивный факториал
constexpr double factorial(unsigned x) {
    if (x == 0) return 1;
    return x * factorial(x - 1);
}

constexpr double const_exp(const double x) {
    double eps = 1e-4; // минимальный размер члена учитываемого в вычислениях
    double result = 0;
    double step = 1;
    if (x >= 0) {
        for (int n = 1; step > eps; n++) {
            result += step;
            step = fast_exp(x, n) / factorial(n); // n-ый член ряда Маклорена экспоненты
        }
        return result;
    } else {
        return 1 / const_exp(-x);
    }
}

int main() {
    constexpr double exponent = 0.1;
    constexpr double a = const_exp(exponent);
    std::cout << "Calculated value for exp(" << exponent << ") = " << a << ", error from std::exp is "
              << a - exp(exponent) << std::endl;

}
