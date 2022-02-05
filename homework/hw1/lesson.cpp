#include <chrono> // библиотека для работы со временем
#include <iostream>
#include <cmath>

using namespace std::chrono;

class Timer {
public:
    Timer() : start(steady_clock::now()) {}

    ~Timer() {
        std::cout << "Time is: " << duration_cast<microseconds>(steady_clock::now() - start).count() << std::endl;
    }

private:
    steady_clock::time_point start;
};

int main() {
    auto result = 0.;
    {
        Timer t;
        for (auto i = 0u; i < 1'000'000; i++) {
            result += sin(i) * cos(i);
        }
    }
    {
        Timer t;
        for (auto i = 0u; i < 1'000'000; i++) {
            result += pow(i, 4);
        }
    }
    return 0;
}
