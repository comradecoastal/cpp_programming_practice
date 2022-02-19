#include <iostream>
#include <map>
#include <set>

int main() {
    std::hash<std::string> str_hash;
    std::cout << str_hash("ass") << '\n';

    std::map<std::string, unsigned> grades;
    grades["Roman"] = 7;

    std::pair<std::string, unsigned> victoria_grade = {"Victoria", 8u};
    std::pair<std::string, unsigned> vladimir_grade = {"Vladimir", 5u};

    grades.insert(victoria_grade);
    grades.insert(vladimir_grade);

    auto denis_grade = std::make_pair("Denis", 3u);
    grades.insert(denis_grade);

    grades.insert({"Yuri", 10u});

    grades.emplace("Mark", 2u);

    std::cout << "Yuri grade " << grades["Yuri"] << '\n';
    std::cout << "Nobody grade " << grades["Nobody"] << '\n';

    for(const auto& [student,grade]: grades) {
        std::cout << student << " " << grade << '\n';
    }


}
