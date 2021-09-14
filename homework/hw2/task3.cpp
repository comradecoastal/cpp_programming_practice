#include <algorithm>
#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& list) {
    int n = list.size();

    // insertion sorting algo
    for (int i = 1; i < n; i++) {
        for (int j = i; (j > 0) && (list.at(j) < list.at(j - 1)); j--) {
            std::swap(list.at(j), list.at(j - 1));
        }
    }
}

int main() {
    int n, m;
    std::vector<int> a;

    std::cout << "Enter the amount of numbers: ";
    std::cin >> n;
    std::cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> m;
        a.push_back(m);
    }

    insertion_sort(a);

    for (auto val: a) {
        std::cout << val << " ";
    }

    return 0;
}