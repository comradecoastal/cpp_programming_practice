#include <iostream>
#include <bitset>

struct DateTime {
    std::bitset<40> field;

    void setDay(int d) {
        if (1 <= d <= 31) {
            std::bitset<5> dBits = static_cast<std::bitset<5>>(d);
            for (int i = 0; i < 5; i++) {
                field[i] = dBits[i];
            }
        }
    }

    int getDay() {
        std::bitset<5> dBits;
        for (int i = 0; i < 5; i++) {
            dBits[i] = field[i];
        }
        return (int) (dBits.to_ulong());
    }

    void setMonth(int m) {
        if (1 <= m <= 12) {
            std::bitset<4> mBits = static_cast<std::bitset<4>>(m);
            for (int i = 5; i < 9; i++) {
                field[i] = mBits[i - 5];
            }
        }
    }

    int getMonth() {
        std::bitset<4> mBits;
        for (int i = 0; i < 4; i++) {
            mBits[i] = field[i + 5];
        }
        return (int) (mBits.to_ulong());
    }

    void setDate(int hour, int min, double sec) {
        int ms = (ms * 10);
        std::cout << ms << std::endl;
    }
};

int main() {
    DateTime date;
    date.setDay(24);
    std::cout << date.getDay() << std::endl;
    date.setDay(1);
    std::cout << date.getDay() << std::endl;
    date.setMonth(6);
    std::cout << date.getMonth() << std::endl;
    date.setDate(2, 2, 15.57);

    return 0;
}
