//
// Created by coastal on 3/11/22.
//

#include "Human.h"

#include <utility>

static std::vector<std::string> search(const std::regex& pattern,
                                const std::string& text) {
    auto begin = std::sregex_iterator(std::begin(text),
                                      std::end(text), pattern);
    auto end = std::sregex_iterator();
    std::vector<std::string> results(std::distance(begin, end));
    std::transform(begin, end, std::back_inserter(results), [](auto x){
        return x.str();
    });
    auto it = std::remove_if(std::begin(results), std::end(results), [](auto item) {
        return item.empty();
    });
    results.erase(it, std::end(results));
    return results;
}

void Human::input_name(std::string new_first_name, std::string new_last_name, std::string new_patronymic) {
    first_name = std::move(new_first_name);
    last_name = std::move(new_last_name);
    patronymic = std::move(new_patronymic);
}

void Human::input_name(std::string new_first_name, std::string new_last_name) {
    first_name = std::move(new_first_name);
    last_name = std::move(new_last_name);
}

void Human::input_phone_number(const std::string& name, const std::string& number) {
    std::regex pattern(R"((\+7|8)(\([4983]\d{2}\)|[4983]\d{2})[0-9]{3}((\s|\-)?\d{2}){2})");
    auto results = search(pattern, number);
    if (results.empty()) throw std::invalid_argument("No valid phone number found");
    PhoneNumbers[name] = results[0];
}

nlohmann::json Human::generate_json() const{
    using nlohmann::json;
    json human_object;
    human_object["first_name"] = first_name;
    human_object["last_name"] = last_name;
    human_object["patronymic"] = patronymic;
    human_object["age"] = age;
    human_object["is_alive"] = is_alive;
    human_object["numbers"] = json(PhoneNumbers);

    return human_object;
}

void Human::read_json(nlohmann::json human_object) {
    first_name = human_object["first_name"];
    last_name = human_object["last_name"];
    patronymic = human_object["patronymic"];
    age = human_object["age"];
    is_alive = human_object["is_alive"];
    PhoneNumbers = human_object["numbers"];
}

std::string Human::dump_json(int n = 0) const{
    return generate_json().dump(n);
}

std::string Human::dump_json() const{
    return generate_json().dump();
}

std::istream &operator>>(std::istream &in, Human& other) {
    nlohmann::json human_object;
    in >> human_object;
    other.read_json(human_object);
    return in;
}

auto Human::output_name() {
    return std::tuple(first_name, last_name, patronymic);
}

unsigned Human::output_age() const {
    return age;
}

bool Human::output_is_alive() const {
    return is_alive;
}

const std::map<std::string, std::string> &Human::output_phone_numbers() {
    return PhoneNumbers;
}

std::string Human::_output_full_name() const {
    return first_name + '_' + last_name + '_' + patronymic + '_' + std::to_string(age);
}

std::string Human::output_readable_name() const {
    return first_name + ' ' + last_name + ' ' + patronymic;
}






