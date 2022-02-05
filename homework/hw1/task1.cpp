#include "Timer.h"
#include <cmath>


int main() {
    {

        Timer<std::chrono::microseconds> t_1(1), t_2(2);
        Timer<std::chrono::milliseconds> t; // Время показанное t будет в 1000 раз меньше чем t_1

        auto result = 0.;
        for (auto i = 0u; i < 1'000'000u; i++) {
            result += cos(i) * sin(i);
        }

        t_2.pause();

        // Во время остановки t_2 работает t_3, так что время показанное t_1 примерно = t_2 + t_3

        {
            Timer<std::chrono::microseconds> t_3(3);

            for (auto i = 0u; i < 1'000'000u; i++) {
                result += pow(i, 4);
            }
        }

        t_2.resume();

        for (auto i = 0u; i < 1'000'000u; i++) {
            result += pow(cos(i), 4);

        }
    }
}
