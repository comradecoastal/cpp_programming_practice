#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

int main() {
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
//    auto generator = std::default_random_engine(current_timestamp); // bad generator :(
    auto generator = std::mt19937_64(current_timestamp); // good generator :)
    auto distribution = std::uniform_int_distribution(1, 10);
    for(auto i = 0; i < 50; i++) {
        std::cout << distribution(generator) << ' '; //distribution is a functional object
    }
    std::cout << "BRUH\n";

    std::vector<int> random_numbers;
    std::generate_n(std::back_inserter(random_numbers), 30, [&generator, &distribution](){
        return distribution(generator);
    });
    for (auto e: random_numbers) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    auto to_remove = std::remove_if(random_numbers.begin(), random_numbers.end(), [](auto elem){return (elem % 2) == 0;});
    random_numbers.erase(to_remove, std::end(random_numbers));
    for (auto e: random_numbers) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
