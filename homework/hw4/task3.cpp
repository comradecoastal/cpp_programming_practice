#include <iostream>
#include <bitset>
#include <vector>

struct DateTime {
    std::bitset<40> field;
    // bits 0 - 29 : milliseconds of day
    // bit 30 - 33 : month
    // bit 34 - 39 : day of moth

    void set_day(unsigned d) {
        // set day
        if (1 <= d && d <= 31) {
            std::bitset<5> dBits = static_cast<std::bitset<5>>(d);
            for (int i = 0; i < 5; i++) {
                field[i + 34] = dBits[i];
            }
        }
    }

    unsigned get_day() {
        // returns day
        std::bitset<5> dBits;
        for (int i = 0; i < 5; i++) {
            dBits[i] = field[i + 34];
        }
        return dBits.to_ulong();
    }

    void set_month(unsigned m) {
        // sets month
        if (1 <= m && m <= 12) {
            std::bitset<4> mBits = static_cast<std::bitset<4>>(m);
            for (int i = 0; i < 4; i++) {
                field[i + 30] = mBits[i];
            }
        }
    }

    unsigned get_month() {
        // returns month
        std::bitset<4> mBits;
        for (int i = 0; i < 4; i++) {
            mBits[i] = field[i + 30];
        }
        return mBits.to_ulong();
    }

    void set_day_ms(unsigned ms) {
        // sets milliseconds in day
        if (0 <= ms && ms <= 86'400'000) {
            std::bitset<30> msBits = static_cast<std::bitset<30>>(ms);
            for (int i = 0; i < 30; i++) {
                field[i] = msBits[i];
            }
        }
    }

    void set_day_time(unsigned h, unsigned m = 0, unsigned s = 0, unsigned ms = 0) {
        // day time using hours, minutes, seconds and milliseconds
        if (0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59 && 0 <= ms && ms <= 999) {
            ms += 1000 * (s + 60 * (m + 60 * h));
            this->set_day_ms(ms);
        }
    }

    int get_day_ms() {
        // returns total number for day milliseconds
        std::bitset<30> msBits;
        for (int i = 0; i < 30; i++) {
            msBits[i] = field[i];
        }
        return (int) (msBits.to_ulong());
    }

    std::vector<unsigned> get_date() {
        /**
         * returns vector following values:
         * {milliseconds, seconds, minutes, hours, day, month}
         */
        unsigned day = this->get_day();
        unsigned month = this->get_month();
        unsigned ms = this->get_day_ms();

        unsigned s = ms / 1000;
        ms %= 1000;
        unsigned m = s / 60;
        s %= 60;
        unsigned h = m / 60;
        m %= 60;

        return {ms, s, m, h, day, month};
    }

    void print_date() {
        std::vector<unsigned> time = this->get_date();
        std::cout << "Date: " << time[4] << '/' << time[5] << ", Time: " << time[3] << ':' << time[2] << ':' << time[1]
                  << ':' << time[0] << std::endl;
    }
};

int main() {
    DateTime date;
    date.set_day(24);
    std::cout << date.get_day() << std::endl;
    date.set_day(1);
    std::cout << date.get_day() << std::endl;
    date.set_month(6);
    std::cout << date.get_month() << std::endl;
    date.set_day_ms(2900003);
    std::cout << date.get_day_ms() << std::endl;

    date.set_day_time(12, 55, 30, 233);

    std::vector<unsigned> time;
    time = date.get_date();

    for (auto element: time) {
        std::cout << element << std::endl;
    }

    date.print_date();

    return 0;
}
