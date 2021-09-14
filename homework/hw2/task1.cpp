#include <iostream>
#include <vector>

int main() {
    std::vector<double> element(2); // vector v
    std::vector<std::vector<double>> tensor(2); // transformation matrix A
    double first, second; // variables for input

    // input v = [x y] vector
    std::cout << "Enter vector values: ";
    std::cin >> first >> second;
    element.at(0) = first;
    element.at(1) = second;

    // input A = [a b ; c d] matrix
    std::cout << "Enter values for transformation matrix: ";
    for (auto &line: tensor) {
        std::cin >> first >> second;
        line.push_back(first);
        line.push_back(second);
    }

    // output v' = A * v vector, v' = [ax + by   cx + dy]
    std::cout << "The transformation is: " << tensor[0][0] * element[0] + tensor[0][1] * element[1] << " "
              << tensor[1][0] * element[0] + tensor[1][1] * element[1] << std::endl;

    return 0;
}
