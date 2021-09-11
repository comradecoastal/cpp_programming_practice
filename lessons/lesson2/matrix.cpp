#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> M(2);
    for(auto& line : M) {
        int left, right;
        std::cin >> left >> right;
        line.push_back(left);
        line.push_back(right);
    }
    std::vector<int> line_sums;
    for (auto& line : M) {
        auto  line_sum = 0;
        for (auto& num: line) {
            line_sum += num;
        }
        line_sums.push_back(line_sum);
    }
    std::cout << std::max(line_sums.at(0), line_sums.at(1)) << std::endl;
    for (auto& line : M) {
        for(auto& num: line) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}