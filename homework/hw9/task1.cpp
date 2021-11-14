#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
void merge(std::vector<T>& A, int iBegin, int iMiddle, int iEnd, std::vector<T>& B) {
    /**
     * Function compares values in A and saves them to B
     */
    int i = iBegin; // beginning of left part
    int j = iMiddle; // beginning of right part
    // compare i-th element to j-th element
    for (int k = iBegin; k < iEnd; k++) {
        if (i < iMiddle && (j >= iEnd || A.at(i) <= A.at(j))) {
            B.at(k) = A.at(i++);
        } else {
            B.at(k) = A.at(j++);
        }
    }
}

template<typename T>
void splitMerge(std::vector<T>& B, int iBegin, int iEnd, std::vector<T>& A){
    /**
     * Function splits vector in two parts (then the parts are sorted) and them merges them
     */
    if (iEnd - iBegin <= 1) return; // if  length of array is 1 it's sorted
    int iMiddle = (iEnd + iBegin) / 2; // midpoint of array
    // A and B switch places each iteration
    splitMerge(A, iBegin, iMiddle, B); // sort left half
    splitMerge(A, iMiddle, iEnd, B); // sort right half
    merge(B, iBegin, iMiddle, iEnd, A); // merge halves
}

template<typename T>
void mergeSort(std::vector<T>& A){
    /**
     * Function performs merge-sort on vector A
     * @param A - vector of integers to be sorted
     */
    std::vector<T> B = A; // make copy of vector A
    size_t n = A.size();
    splitMerge(B, 0, n, A); // run merge sort
}

int main() {
    // now works for double
    std::vector<double> array = {10.3, 3, 5, 1.1, 7.9, 8, 9, 2, 4, 6};
    mergeSort(array);
    for (auto elen : array) {
        std::cout << elen << " ";
    }
    std::cout << std::endl;

    // строки сортируются в порядке таблицы unicode
    std::vector<std::string> string_vector= {"Bruh", "barebuh", "aoaoaoao", "aboba", "8", "$", "%", ".", "Д"};
    mergeSort(string_vector);
    for (auto elen : string_vector) {
        std::cout << elen << " ";
    }
    std::cout << std::boolalpha << std::endl;

    // сортировка bool
    std::vector<bool> bool_vector= {true, false, false, true, false};
    mergeSort(bool_vector);
    for (auto elen : bool_vector) {
        std::cout << elen << " ";
    }
    std::cout << std::endl;

    return 0;
}

