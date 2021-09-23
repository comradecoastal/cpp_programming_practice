#include <iostream>

long long fibonacci(long long n) {
    /**
     * Function returns n-th fibonacci number.
     */
    return (n == 1 || n == 2) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n;

    std::cout << "Enter position of fibonacci number (int): ";
    std::cin >> n;

    std::cout << "The fibonacci number is: " << fibonacci(n) << std::endl;

    return 0;
}
