#ifndef DEFAULT_TIMER_H
#define DEFAULT_TIMER_H

#include <chrono>
#include <iostream>

using namespace std::chrono;

template<typename T>
class Timer {
public:
    Timer() : start(steady_clock::now()), duration(0), id(0) {}
    explicit Timer(int id): start(steady_clock::now()), duration(0), id(id) {}

    void pause() {
        duration += steady_clock::now() - start;
        std::cout << "Timer " << id << " paused. Time is: " << duration_cast<T>(duration).count() << std::endl;
    }

    void resume() {
        start = steady_clock::now();
    }

    ~Timer() {
        duration += steady_clock::now() - start;
        std::cout << "Timer " << id << ". Time is: " << duration_cast<T>(duration).count() << std::endl;
    }

private:
    steady_clock::time_point  start;
    steady_clock::duration duration;
    int id;
};


#endif //DEFAULT_TIMER_H
