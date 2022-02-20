//
// Created by coastal on 2/20/22.
//

#ifndef DEFAULT_PHONEBOOK_H
#define DEFAULT_PHONEBOOK_H

#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <tuple>
#include <string>

class Name {
public:
    Name(const std::string &last_name, const std::string &first_name, const std::string &patronymic) :
            fio(last_name, first_name, patronymic) {}

    [[nodiscard]] std::string first_name() const {
        return get<0>(fio);
    }

    bool operator<(const Name &other) {
        return fio < other.fio;
    }

    bool operator<(const std::string &first_name) {
        return std::get<0>(fio) < first_name;
    }

    friend bool operator<(const Name &lhs, const std::string &rhs) {
        return std::get<0>(lhs.fio) < rhs;
    }

    friend bool operator<(const std::string &lhs, const Name &rhs) {
        return lhs < std::get<0>(rhs.fio);
    }

    friend bool operator<(const Name &lhs, const Name &rhs) {
        return lhs.fio < rhs.fio;
    }


    friend std::ostream &operator<<(std::ostream &out, const Name &other) {
        out << std::get<0>(other.fio) << ' ' << std::get<1>(other.fio) << ' ' << std::get<2>(other.fio);
        return out;
    }

private:
    std::tuple<std::string, std::string, std::string> fio;

};

class Phonebook {
public:
    Phonebook() = default;

    void add_entry(const Name &new_name, unsigned long new_number) {
        storage.emplace(new_name, new_number);
    }

    std::size_t size() {
        return std::size(storage);
    }

    std::pair<Name, unsigned long> access_by_number(unsigned long n) {
        // find entry by number
        // if number to large returns last entry
        if (n >= std::size(storage)) n = std::size(storage) - 1; // avoid error
        return *std::next(std::begin(storage), n);
    }

    std::pair<Name, unsigned long> find_by_name(const std::string &first_name) {
        // finds an entry with matching first name
        // if no matching entry is found returns last entry
        auto it = storage.begin();
        for (; std::get<0>(*it) < first_name; it++);
        if ((std::get<0>(*it)).first_name() == first_name) return *it;
        return *std::prev(storage.end());
    }

    std::pair<Name, unsigned long> access_random() {
        auto number = random_int();
        return access_by_number(number % std::size(storage));
    }

private:
    std::multimap<Name, unsigned long> storage;

    static long random_int() {
        auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
        auto generator = std::mt19937_64(current_timestamp); // good generator :)
        auto distribution = std::uniform_int_distribution();

        return distribution(generator);
    }
};


#endif //DEFAULT_PHONEBOOK_H
