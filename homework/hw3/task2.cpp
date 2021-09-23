#include <vector>
#include <iostream>

void merge(std::vector<int>& A, int iBegin, int iMiddle, int iEnd, std::vector<int>& B) {
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

void splitMerge(std::vector<int>& B, int iBegin, int iEnd, std::vector<int>& A){
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

void mergeSort(std::vector<int>& A){
    /**
     * Function performs merge-sort on vector A
     * @param A - vector of integers to be sorted
     */
    std::vector<int> B = A; // make copy of vector A
    int n = A.size();
    splitMerge(B, 0, n, A); // run merge sort
}

int main() {
    std::vector<int> array = {10, 3, 5, 1, 7, 8, 9, 2, 4, 6};
    mergeSort(array);
    for (auto elen : array) {
        std::cout << elen << " ";
    }

    return 0;
}

