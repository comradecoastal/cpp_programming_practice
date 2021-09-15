#include <algorithm>
#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& list) {
    /**
     * Function for sorting list of integers.
     * Uses insertion sort.
     *
     * @param list link to list of integers.
     */
    int n = list.size();

    // insertion sorting algo
    for (int i = 1; i < n; i++) {
        for (int j = i; (j > 0) && (list.at(j) < list.at(j - 1)); j--) {
            std::swap(list.at(j), list.at(j - 1));
        }
    }
}

int main() {
    int n, tmp;
    std::vector<int> list;

    std::cout << "Enter the amount of numbers: ";
    std::cin >> n;
    std::cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        list.push_back(tmp);
    }

    insertion_sort(list);

    for (auto val: list) {
        std::cout << val << " ";
    }

    return 0;
}