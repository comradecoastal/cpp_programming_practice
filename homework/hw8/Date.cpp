//
// Created by coastal on 11/4/21.
//

#include "Date.h"
using namespace Dates;


std::ostream &Dates::operator<<(std::ostream &out, Date &date) {
    out << ((date.day < 10) ? "0" : "") << date.day << '/'
        << ((static_cast<int>(date.month) < 10) ? "0" : "") << static_cast<int>(date.month) << '/' << date.year;
    return out;
}

std::istream &Dates::operator>>(std::istream &in, Date &date) {
    int mm, dd, yy;
    in >> dd >> mm >> yy;
    date = Date(dd, mm, yy);
    return in;
}

bool Dates::operator>(Date &lhs, Date &rhs) {
    if (lhs.year > rhs.year) return true;
    if (lhs.year == rhs.year) {
        if (lhs.month > rhs.month) return true;
        if (lhs.month == rhs.month) {
            if (lhs.day > rhs.day) return true;
        }
    }
    return false;
}

bool Dates::operator<(Date &lhs, Date &rhs) {
    if (lhs.year < rhs.year) return true;
    if (lhs.year == rhs.year) {
        if (lhs.month < rhs.month) return true;
        if (lhs.month == rhs.month) {
            if (lhs.day < rhs.day) return true;
        }
    }
    return false;
}

bool Dates::operator>=(Date &lhs, Date &rhs) {
    if (lhs.year > rhs.year) return true;
    if (lhs.year == rhs.year) {
        if (lhs.month > rhs.month) return true;
        if (lhs.month == rhs.month) {
            if (lhs.day >= rhs.day) return true;
        }
    }
    return false;
}

bool Dates::operator<=(Date &lhs, Date &rhs) {
    if (lhs.year < rhs.year) return true;
    if (lhs.year == rhs.year) {
        if (lhs.month < rhs.month) return true;
        if (lhs.month == rhs.month) {
            if (lhs.day <= rhs.day) return true;
        }
    }
    return false;
}

bool Dates::operator==(Date &lhs, Date &rhs) {
    return (lhs.year == rhs.year) && (lhs.month == rhs.month) && (lhs.day == rhs.day);
}
