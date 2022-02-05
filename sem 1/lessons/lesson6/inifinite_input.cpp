#include <iostream>
#include <vector>

int main() {
    std::string s;
    std::vector<std::string> lines;

    for (;std::getline(std::cin, s);) lines.push_back(s);
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
}

