//
// Created by coastal on 11/4/21.
//
#include "Date.h"
#include <iomanip>
#include <iostream>


int main() {
    using Dates::Date;

    Date a(6 ,8, 2002);
    std::cout << a << std::endl;
    std::cin >> a;
    std::cout << a << std::endl;

    Date b(6, 9, 2002);
    Date c(7, 8, 2002);
    Date d(6, 8, 2001);


    std::cout << std::boolalpha << (a <= a) << (a < a) << (a == a) << (a < b) << (a > c) << (a >= d) << std::endl;

}