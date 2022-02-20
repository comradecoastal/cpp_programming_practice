#include <algorithm>
#include <array>
#include <chrono>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <random>
#include <vector>

using namespace std::chrono;

int random_int() {
    // random int generator
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution();

    return distribution(generator);
}

auto time_test(auto &container, int n) {
    // time test for array, vector and deque
    steady_clock::duration duration(0);
//    std::cout << duration_cast<microseconds>(duration).count() << std::endl;
    steady_clock::time_point start;
    for (auto i = 0; i < n; i++) {
        std::generate(std::begin(container), std::end(container), random_int); // fill container with random values

        start = steady_clock::now();
        std::sort(std::begin(container), std::end(container));
        duration += steady_clock::now() - start;
//        std::cout << duration_cast<microseconds>(duration).count() << std::endl;

    }

    return duration_cast<microseconds>(duration).count();
}

auto time_test_list(auto &container, int n) {
    // time test for list
    steady_clock::duration duration(0);
    steady_clock::time_point start;
    for (auto i = 0; i < n; i++) {
        std::generate(std::begin(container), std::end(container), random_int);  // fill container with random values

        start = steady_clock::now();
        container.sort();
        duration += steady_clock::now() - start;
//        std::cout << duration_cast<microseconds>(duration).count() << std::endl;
    }

    return duration_cast<microseconds>(duration).count();
}

int main() {
    const int N = 1000; // length of
    const int M = 1000; // number of tests per container
    std::array<int, N> sort_array{};
    std::vector<int> sort_vector(N);
    std::deque<int> sort_deque(N);
    std::list<int> sort_list(N);
    std::forward_list<int> sort_forward_list(N);

    std::cout << "Number of elements: " << N << ", number of tests: " << M << std::endl;
    std::cout << "Time to sort arrays:        " << time_test(sort_array, M) << std::endl;
    std::cout << "Time to sort vectors:       " << time_test(sort_vector, M) << std::endl;
    std::cout << "Time to sort deques:        " << time_test(sort_deque, M) << std::endl;
    std::cout << "Time to sort lists:         " << time_test_list(sort_list, M) << std::endl;
    std::cout << "Time to sort forward lists: " << time_test_list(sort_forward_list, M) << std::endl;
    std::cout << "Testing finished!" << std::endl;

    // winner is array

    return 0;
}

