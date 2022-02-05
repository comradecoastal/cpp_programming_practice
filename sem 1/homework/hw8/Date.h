//
// Created by coastal on 11/4/21.
//

#ifndef DEFAULT_DATE_H
#define DEFAULT_DATE_H

#include <iostream>
#include <stdexcept>
#include <string>

namespace Dates {
    enum class Month;

    static unsigned days_in_month(const Dates::Month &, int);

    class Date;

}

enum class Dates::Month {
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

unsigned Dates::days_in_month(const Dates::Month &month, int year) {
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


class Dates::Date {
public:
    Date() : year(1970), month(Month::JAN), day(1) {}

    Date(unsigned int dd, unsigned mm, int yy) : Date(dd, Month(mm), yy) {}

    Date(unsigned dd, Month mm, int yy) : day(dd), month(mm), year(yy) {
        if (dd == 0 || static_cast<unsigned>(mm) == 0 || yy == 0) {
            throw std::invalid_argument("Numbering in dates starts with 1. There is no year 0, moth 0, or day 0.");
        }
        if (static_cast<unsigned>(mm) > 12) {
            throw std::invalid_argument("There are only 12 moths, but the number received was: " +
                                        std::to_string(static_cast<unsigned>(mm)));
        }
        if (dd > days_in_month(month, year))
            throw std::invalid_argument("There are only " + std::to_string(
                    days_in_month(month, year)) + " days in moth " + std::to_string(static_cast<unsigned >(mm)) +
                                        ", but the number received was: " + std::to_string(dd));
    }

    // getters
    unsigned get_day() const{
        return day;
    }

    Month get_month() const{
        return month;
    }

    int get_year() const {
        return year;
    }

    // operators

    friend std::ostream& operator << (std::ostream & out, Date& date);
    friend std::istream& operator >> (std::istream & in, Date& date);

    friend bool operator > (Date& lhs, Date& rhs);
    friend bool operator < (Date& lhs, Date& rhs);
    friend bool operator >= (Date& lhs, Date& rhs);
    friend bool operator <= (Date& lhs, Date& rhs);
    friend bool operator == (Date& lhs, Date& rhs);


private:
    int year;
    Month month;
    unsigned day;
};


#endif //DEFAULT_DATE_H
