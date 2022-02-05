#include <iostream>
#include <vector>

int main() {
    std::vector<double> element(3); // vector v
    std::vector<std::vector<double>> tensor(3); // transformation matrix A
    double first, second; // variables for input

    // input v = [x y z] vector
    std::cout << "Enter vector values: ";
    for (auto i = 0; i < 3; std::cin >> element.at(i++));

    // input A = [a b c; d e f; g h i] matrix
    std::cout << "Enter values for transformation matrix: ";
    for (auto &line: tensor) {
        line.resize(3);
        for (auto i = 0; i < 3; std::cin >> line.at(i++));
    }

    // output v' = A * v vector, v' = [ax + by + cz ; dx + ey + fz ; gx + hy + iz]
    std::cout << "The transformation is: ";
    for (auto &line: tensor) {
        std::cout << line.at(0) * element.at(0) + line.at(1) * element.at(1) +
                     +line.at(2) * element.at(2) << " ";
    }

    std::cout << std::endl;

    return 0;
}
