#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int bin_search(int val, std::vector<int>& list) {
    int right = list.size();
    int left = 0;
    int middle;
    bool numberFound = false;

    while (left != right) {
        middle = (left + right) / 2;
        if (list.at(middle) == val) {
            numberFound = true;
            right = left = middle;
        } else if (val < list.at(middle)) {
            right = middle - 1;
        } else if (list.at(middle) < val) {
            left = middle + 1;
        }
    }

    if (numberFound) {
        return middle;
    } else {
        return -1;
    }
}

int main() {
    int n, val, tmp, pos;
    std::vector<int> list;

    std::cout << "Enter the amount of numbers: ";
    std::cin >> n;
    std::cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        list.push_back(tmp);
    }
    std::cout << "Enter search value: ";
    std::cin >> val;

    pos = bin_search(val, list);



    return 0;
}
