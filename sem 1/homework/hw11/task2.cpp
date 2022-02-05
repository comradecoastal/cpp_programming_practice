#include <iostream>

constexpr unsigned long prime(unsigned n) {
    if (n == 1) return 2;
    unsigned place = 2;
    unsigned long number = 3;
    bool is_prime = true;
    for (unsigned long i = 3; place < n; i++) {
        is_prime = true;
        for (unsigned long j = 2; j < (i / 2 + 1); j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            number = i;
            place += 1;
        }
    }
    return number;
}

int main() {
    constexpr unsigned long a = prime(6);
    std::cout << a << std::endl;
}