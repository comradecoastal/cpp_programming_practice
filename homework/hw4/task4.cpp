#include <iostream>

enum class Month {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int daysInMonth(const Month &month, int year) {
    switch (month) {
        case Month::FEB:
            if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
                return 29;
            } else {
                return 28;
            }

        case Month::APR:
        case Month::JUN:
        case Month::SEP:
        case Month::NOV:
            return 30;
        default:
            return 31;
    }
}

int main() {
    int n, y;

    std::cout << "Enter number of month: ";
    std::cin >> n;
    std::cout << "Enter year: ";
    std::cin >> y;
    std::cout << "The number of days in this month is: " << daysInMonth(static_cast<Month>(n), y) << std::endl;
}