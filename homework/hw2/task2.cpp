#include "Phonebook.h"
#include <iostream>
#include <map>

int main() {

    Phonebook book;
    book.add_entry(Name("popkin", "vasya", "vasilyevich"), 8'922'228'13'37u);
    book.add_entry(Name("petrovich", "arkasha", "palych"), 8'922'000'13'37u);
    book.add_entry(Name("kartashov", "kostya", "pavlovich"), 8'922'777'77'77);
    book.add_entry(Name("ovchinkin", "vova", "sanych"), 8'922'123'45'67);

    auto entry = book.access_by_number(0);
    std::cout << std::get<0>(entry) << ' ' << std::get<1>(entry) << std::endl;


    std::cout << "\nAccess by number: \n";
    for (auto i = 0; i<7; i++) {
        entry = book.access_by_number(i);
        std::cout << i << ": " << std::get<0>(entry) << ' ' << std::get<1>(entry) << std::endl;
    }

    std::cout << "\nFind by name: \n";
    entry = book.find_by_name("kar");
    std::cout << std::get<0>(entry) << ' ' << std::get<1>(entry) << std::endl;
    entry = book.find_by_name("kartashov");
    std::cout << std::get<0>(entry) << ' ' << std::get<1>(entry) << std::endl;
    entry = book.find_by_name("ovchinkin");
    std::cout << std::get<0>(entry) << ' ' << std::get<1>(entry) << std::endl;
    entry = book.find_by_name("petrovich");
    std::cout << std::get<0>(entry) << ' ' << std::get<1>(entry) << std::endl;

    std::cout << "\nRandom access: \n";
    for (auto i = 0; i<5; i++) {
        entry = book.access_random();
        std::cout << std::get<0>(entry) << ' ' << std::get<1>(entry) << std::endl;
    }
    return 0;
}

