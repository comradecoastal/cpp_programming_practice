#include <algorithm>
#include <iostream>
#include <vector>

int main() {

    std::vector<int> list = {10, 3, 5, 1, 7, 8, 9, 2, 4, 6};

    // print thing
    auto print = [&list](){
        for (auto a : list){
            std::cout << a << ' ';
        }  std::cout << std::endl;
    };

    // sorts vector in ascending order if ascending == true, and descending ascending == false;
    auto newSort = [](auto& sorted, bool ascending){
        if (ascending) {
            std::sort(sorted.begin(), sorted.end()); // default sort
        } else {
            std::sort(sorted.begin(), sorted.end(), [](int a, int b) { return a > b;}); // descending sort
        }
    };

    newSort(list, false);
    print();

    return 0;
}
