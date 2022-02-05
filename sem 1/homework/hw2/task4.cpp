#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int bin_search(int val, std::vector<int>& list) {
    /**
     * Find the position of val in list of integers.
     * Returns position of value if found, or -1 if not found.
     *
     * @param val the value
     * @param list link to list of integers
     * @return integer equal to position, -1 if not found
     */

    int right = list.size(); // initial right position
    int left = 0; // initial left position
    int middle; // variable for middle value
    bool numberFound = false; // number found value

    // binary search algo
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

    // return position of found or -1 if not found
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

    std::cout << pos << std::endl;


    return 0;
}
