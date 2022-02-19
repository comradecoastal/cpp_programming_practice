#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#define RANGE(container) container.begin(), container.end()

template <typename T>
std::ostream& operator<< (std::ostream& out,const std::vector<T>& vector) {
    out << '[';
//    std::copy(std::begin(vector), std::end(vector), std::ostream_iterator<T>(out, ", "));
//    out << "\b\b]";
    std::copy(std::begin(vector), std::prev(std::end(vector)), std::ostream_iterator<T>(out, ", "));
    out << *std::prev(std::end(vector)) << "]";

    return out;
}

int main() {

    auto n1 = 45, n2 = 25;
    std::cout << std::gcd(45, 25) << ' ' << std::lcm(25, 45) << '\n';

    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // apply function to each element
    std::for_each(numbers.begin(), numbers.end(), [](auto &elem){elem *= elem;});
    std::for_each(numbers.begin(), numbers.end(), [](auto elem){std::cout << elem << ' ';});
    std::cout << std::endl;

    // generate ascending numbers
    std::vector<int> gen_num(10);
    std::iota(gen_num.begin(), gen_num.end(), 2);
    for(auto elem: gen_num) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    // sum of elements
    std::cout << std::accumulate(std::next(gen_num.begin(), 5),  gen_num.end(), 0) << std::endl;
    // product of elements
    std::cout << std::accumulate(gen_num.begin(), std::next(gen_num.begin(), 3), 1,
                                 [](auto lhs, auto rhs){return lhs*rhs;}) << std::endl;

    // inner product
    std::vector<int> v1{1, 2, 3, 4, 5}, v2{1, 1, 1, 1, 0};
    std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0) << std::endl;
    // reverse copy of v1 to v2
    std::reverse_copy(v1.begin(), v1.end(), v2.begin());
    std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0) << std::endl;

    // back inserter for empty vector (front_inserter for deque, inserter for set)
    std::vector<int> v3;
    std::copy(gen_num.begin(), gen_num.end(), std::back_inserter(v3));
    for (auto e: v3) {std::cout << e << ' ';}
    std::cout << std::endl;

    // copy into ostream iterator + macro
    std::copy(RANGE(v3), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // test output
    std::cout << v3 << std::endl;

    // transform algo
    std::vector<int> squared;
    std::transform(RANGE(v3), std::back_inserter(squared), [](auto elem){return elem * elem;});
    std::cout << squared << std::endl;

    // inner product realization
    std::vector<int> product;
    std::transform(RANGE(v1), std::begin(v2), std::back_inserter(product),
                   [](auto lhr, auto rhs){return lhr * rhs;});
    std::cout << product << ' ' << std::accumulate(RANGE(product), 0) << std::endl;

    return 0;
}