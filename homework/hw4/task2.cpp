// Регулярные выражения
// шаблоны, по которым производится поиск в тексте

#include <regex>
#include <iostream>

std::vector<std::string> search(const std::regex &pattern,
                                const std::string &text) {
    auto begin = std::sregex_iterator(std::begin(text),
                                      std::end(text), pattern);
    auto end = std::sregex_iterator();
    std::vector<std::string> results(std::distance(begin, end));
    std::transform(begin, end, std::back_inserter(results), [](auto x) {
        return x.str();
    });
    auto it = std::remove_if(std::begin(results), std::end(results), [](auto item) {
        return item.empty();
    });
    results.erase(it, std::end(results));
    return results;
}

int main() {

    std::string date_pre_pattern =
            R"(([0-3][0-9])(\.)(0[0-9]|1[0-2])(\.)(\d{2}|\d{4}))" // DD.MM.YYYY DD.MM.YY
            "|"
            R"(([0-3][0-9])(\-)(0[0-9]|1[0-2])(\-)(\d{2}|\d{4}))" // DD-MM-YYYY DD-MM-YY
            "|"
            R"((\d{2}|\d{4})(\.)(0[0-9]|1[0-2])(\.)([0-3][0-9]))" // YYYY.MM.DD YY.MM.DD
            "|"
            R"((\d{2}|\d{4})(\-)(0[0-9]|1[0-2])(\-)([0-3][0-9]))" // YYYY-MM-DD YY-MM-DD
    ;

    std::string time_pre_pattern =
            R"((([0-1][0-9])|(2[0-3]))((:)([0-5][0-9])){2})" // HH:MM:SS
    ;

//    std::cout << date_pre_pattern << std::endl;

    std::regex time_pattern(time_pre_pattern);
    std::regex date_pattern(date_pre_pattern);
    std::string text = "19:10:72 00:00:00 12:65:12 "
                       "31.01.2022 23.13.2025 01-12-22 01:22:12 ";

    std::cout << "Fond times:\n";
    auto search_result = search(time_pattern, text);
    for (const auto &item: search_result) {
        std::cout << item << '\n';
    }

    std::cout << "Found dates:\n";
    search_result = search(date_pattern, text);
    for (const auto &item: search_result) {
        std::cout << item << '\n';
    }

    return 0;
}