#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double a, b, c, d; // quadratic equation coefficients (a, b, c) + discriminant (d)

    // input coefficients
    std::cout << "Quadratic equation solver\nax^2 + bx + c = 0" << std::endl;
    std::cout << "Input 'a' coefficient: ";
    std::cin >> a;
    std::cout << "Input 'b' coefficient: ";
    std::cin >> b;
    std::cout << "Input 'c' coefficient: ";
    std::cin >> c;

    // set output float precision to 3 points
    std::cout << std::setprecision(3);

    if (a == 0) {
        // linear case
        std::cout << "The only solution is x = " << -c / b << std::endl;
    } else {
        d = b * b - 4 * a * c; // discriminant
        if (d == 0) {
            // one solution
            std::cout << "The only solution is x = " << -b / 2 / a << std::endl;
        } else if (d > 0) {
            // two solutions
            std::cout << "The solutions are x = " << (-b + sqrt(d)) / 2 / a
                      << " and x = " << (-b - sqrt(d)) / 2 / a << std::endl;
        } else {
            // no solutions
            std::cout << "There are no solutions.";
        }
    }

    return 0;
}