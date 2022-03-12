//
// Created by coastal on 3/11/22.
//

#ifndef DEFAULT_HUMAN_H
#define DEFAULT_HUMAN_H

#include <exception>
#include <map>
#include <regex>
#include <string>
#include <tuple>

#include "json.hpp"

class Human {
public:
    Human() = default;

    // field setters
    void input_name(std::string new_first_name, std::string new_last_name, std::string new_patronymic);
    void input_name(std::string new_first_name, std::string new_last_name);
    void resurrect() { is_alive = true;}
    void kill() {is_alive = false;}
    void input_age(unsigned short new_age) {age = new_age;}
    void input_phone_number(const std::string& name, const std::string& number);
    // field getters
    auto output_name();
    unsigned output_age() const;
    bool output_is_alive() const;
    const std::map<std::string, std::string>& output_phone_numbers();
    // json functions
    void read_json(nlohmann::json human_object);
    nlohmann::json generate_json() const;
    std::string dump_json(int) const;
    std::string dump_json() const;
    // input operator
    friend std::istream& operator >> (std::istream& in, Human& other);
    // output name stings
    std::string _output_full_name() const;
    std::string output_readable_name() const;

    ~Human() = default;

private:

    std::string first_name;
    std::string last_name;
    std::string patronymic;

    bool is_alive = true;
    unsigned short age = 0;

    // PhoneNumbers map-type : key - type of number, value - valid russian phone number
    std::map<std::string, std::string> PhoneNumbers;

};


#endif //DEFAULT_HUMAN_H
