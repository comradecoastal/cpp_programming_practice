#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#define RANGE(container) container.begin(), container.end() // macro good

// container output
template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vector) {
    out << '[';
    std::copy(std::begin(vector), std::end(vector), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]"; // shaitan machine

    return out;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    for (unsigned i = 2; i <= std::sqrt(n); i++) {
        if ((n % i) == 0) return false;
    }
    return true;
}


int main() {
    std::vector<int> p1;

    // task 1
    p1.resize(10);
    std::iota(RANGE(p1), 1);
    std::cout << "Generated sequence P1: " << p1 << std::endl;

    // task 2
    std::cout << "Enter the number of integers you would like to enter: ";
    int n;
    std::cin >> n;
    std::cout << "Enter " << n << " integers:\n";
    std::generate_n(std::back_inserter(p1), n, [](){int m; std::cin >> m; return m;});
    std::cout << "Added input numbers to P1: " << p1 << std::endl;

    // task 3
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937(seed); // sow the seeds of destruction
    std::shuffle(RANGE(p1), generator);
    std::cout << "Shuffled P1: " << p1 << std::endl;

    // task 4
    std::sort(RANGE(p1));
    auto last = std::unique(RANGE(p1));
    p1.erase(last, p1.end());
    std::cout << "Removed duplicates from P1" << p1 << std::endl;

    // task 5
    int count = 0;
    std::for_each(RANGE(p1), [&count](int x) { count += x % 2; });
    std::cout << "There are " << count << " odd numbers in P1!" << std::endl;

    // task 6
    std::cout << "min value in P1: " << *std::min_element(RANGE(p1))
              << ", max value " << *std::max_element(RANGE(p1)) << std::endl;

    // task 7
    std::shuffle(RANGE(p1), generator); // shuffle for prime finding
    std::cout << "Shuffled P1: " << p1 << std::endl;
    bool found_prime = false;
    for (auto val: p1) {
        if (is_prime(val)) {
            std::cout << "Found prime number in P1: " << val << std::endl;
            found_prime = true;
            break;
        }
    }
    if (not found_prime) std::cout << "No primes found in P1" << std::endl;

    // task 8
    std::transform(RANGE(p1), p1.begin(), [](auto x) { return x * x; });
    std::cout << "Squared numbers in P1" << p1 << std::endl;

    // task 9
    auto distribution = std::uniform_int_distribution(-100, 100);
    std::vector<int> p2;
    std::generate_n(std::back_inserter(p2), std::size(p1),
                    [&distribution, &generator]() { return distribution(generator); });
    std::cout << "Generated random sequence P2" << p2 << std::endl;

    // task 10
    std::cout << "Sum of numbers in P2 = " << std::accumulate(RANGE(p2), 0) << std::endl;

    // task 11
    int m = 4;
    std::transform(p2.begin(), std::next(p2.begin(), m), p2.begin(), [](int x) { return 1; });
    std::cout << "Replaced first " << m << " numbers in P2 with 1: " << p2 << std::endl;

    // task 12
    std::vector<int> p3;
    std::transform(RANGE(p1), p2.begin(), std::back_inserter(p3), [](auto lhs, auto rhs) { return lhs - rhs; });
    std::cout << "Generated sequence P3 as the residual of the elements of P1 and P2: " << p3 << std::endl;

    // task 13
    std::transform(RANGE(p3), p3.begin(), [](auto x) { return (x < 0) ? 0 : x; });
    std::cout << "Replaced all negative numbers in P3 with 0: " << p3 << std::endl;

    // task 14
    last = std::remove_if(RANGE(p3), [](auto x) { return x == 0; });
    p3.erase(last, p3.end());
    std::cout << "Removed all zero elements from P3: " << p3 << std::endl;

    // task 15
    std::reverse(RANGE(p3));
    std::cout << "Reversed order of elements in P3 " << p3 << std::endl;

    // task 16
    std::nth_element(p3.begin(), std::next(p3.begin(), 2), p3.end(), std::greater{});
    std::nth_element(p3.begin(), std::next(p3.begin(), 1), p3.end(), std::greater{});
    std::cout << "Top 3 larges elements in p#: " << p3.at(0) << ", " << p3.at(1) << ", "
              << p3.at(2) << std::endl;

    // task 17
    std::sort(RANGE(p1));
    std::sort(RANGE(p2));
    std::cout << "Sorted P1: " << p1 << "\nAnd sorted P2: " << p2 << std::endl;

    // task 18
    std::vector<int> p4;
    std::merge(RANGE(p1), RANGE(p2), std::back_inserter(p4));
    std::cout << "Generated sequence P4 by merging P1 and P2: " << p4 << std::endl;

    // task 19
    auto lower = --std::lower_bound(RANGE(p4), 1);
    auto upper = std::upper_bound(RANGE(p4), 1);
    std::cout << "The value 1 can be inserted into P4 between elements " << std::distance(p4.begin(), lower) << '('
              << *lower << ") and " << std::distance(p4.begin(), upper) << '(' << *upper << ')' << std::endl;

    // task 20
    std::cout << "P1: " << p1 << std::endl;
    std::cout << "P2: " << p2 << std::endl;
    std::cout << "P3: " << p3 << std::endl;
    std::cout << "P4: " << p4 << std::endl;


}
