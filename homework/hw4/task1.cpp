#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "Human.h"

namespace fs = std::filesystem;
using nlohmann::json;

void make_human_dir() {
    // makes "Humans directory if there is none
    if (!fs::exists("../Humans")) {
        fs::create_directory("../Humans");
    }
}

void make_human_file(const Human &human) {
    make_human_dir();
    fs::path human_path("../Humans");
    human_path = human_path / (human._output_full_name() + ".json");
    std::fstream fout(human_path, std::ios::out);
    fout << human.dump_json();
    fout.close();
}

void delete_human_file(const Human &human) {
    make_human_dir();
    fs::path human_path("../Humans");
    human_path = human_path / (human._output_full_name() + ".json");
    fs::remove(human_path);
}

std::vector<Human> read_human_files() {
    std::vector<Human> output;

    fs::path human_path("../Humans");
    fs::directory_iterator begin(human_path);
    fs::directory_iterator end;

    for (auto it = begin; it != end; it++) {
        auto path = it->path();
        Human read_human;
        std::fstream fin(path, std::ios::in);
//        std::string file_string;
//        for (std::string line; std::getline(fin, line); file_string += line);
//        read_human =
        fin >> read_human;
        fin.close();
        output.push_back(read_human);
    }

    return output;
}

int main() {
    std::cout << "╔╗ ╔╗╔╗ ╔╗╔═╗╔═╗╔═══╗╔═╗ ╔╗    ╔═══╗╔═══╗╔════╗╔═══╗╔══╗ ╔═══╗╔═══╗╔═══╗\n"
                 "║║ ║║║║ ║║║║╚╝║║║╔═╗║║║╚╗║║    ╚╗╔╗║║╔═╗║║╔╗╔╗║║╔═╗║║╔╗║ ║╔═╗║║╔═╗║║╔══╝\n"
                 "║╚═╝║║║ ║║║╔╗╔╗║║║ ║║║╔╗╚╝║     ║║║║║║ ║║╚╝║║╚╝║║ ║║║╚╝╚╗║║ ║║║╚══╗║╚══╗\n"
                 "║╔═╗║║║ ║║║║║║║║║╚═╝║║║╚╗║║     ║║║║║╚═╝║  ║║  ║╚═╝║║╔═╗║║╚═╝║╚══╗║║╔══╝\n"
                 "║║ ║║║╚═╝║║║║║║║║╔═╗║║║ ║║║    ╔╝╚╝║║╔═╗║ ╔╝╚╗ ║╔═╗║║╚═╝║║╔═╗║║╚═╝║║╚══╗\n"
                 "╚╝ ╚╝╚═══╝╚╝╚╝╚╝╚╝ ╚╝╚╝ ╚═╝    ╚═══╝╚╝ ╚╝ ╚══╝ ╚╝ ╚╝╚═══╝╚╝ ╚╝╚═══╝╚═══╝\n"
                 "VERSION 1.0\n";

    std::string commands_help = "Available commands: \n"
                                "add - create new human entry\n"
                                "list - display list of human entries\n"
                                "show - show details of an entry\n"
                                "delete - delete human entry\n"
                                "help - show this list.";
    std::cout << commands_help << std::endl;

    auto loop = true;
    std::string command;

    while (loop) {
        std::cout << "Enter command > ";
        std::cin >> command;

        if (command == "add") {
            std::string input_1;
            std::string input_2;
            std::string input_3;
            int age;

            Human new_entry;
            std::cout << "Enter first name > ";
            std::cin >> input_1;
            std::cout << "Enter last name > ";
            std::cin >> input_2;
            std::cout << "Enter patronymic > ";
            std::cin >> input_3;
            new_entry.input_name(input_1, input_2, input_3);
            std::cout << "Enter age > ";
            std::cin >> age;
            new_entry.input_age(age);

            bool phone_loop = true;
            while (phone_loop) {
                std::cout << "Would you like to add a phone number? [y/n] > ";
                std::cin >> input_1;
                if (input_1 == "n") phone_loop = false;
                else if (input_1 == "y") {
                    std::cout << "Enter title > ";
                    std::cin >> input_2;
                    std::cout << "Enter valid phone number > ";
                    std::cin >> input_3;
                    try {
                        new_entry.input_phone_number(input_2, input_3);
                    } catch (std::invalid_argument &e) {
                        std::cout << "No valid number entered" << std::endl;
                    }
                }
            }

            make_human_file(new_entry);
            std::cout << "New human created!" << std::endl;
            // list command prints a list of stored humans
        } else if (command == "list") {
            std::cout << "List of stored humans: " << std::endl;
            auto humans = read_human_files();
            for (auto i = 0; i < humans.size(); i++) {
                std::cout << i + 1 << ". " << humans.at(i).output_readable_name() << '\n';
            }
            // show command prints data of specified human
        } else if (command == "show") {
            auto humans = read_human_files();
            int n;
            std::cout << "Enter number of person to be shown > ";
            std::cin >> n;
            try {
                auto human = humans.at(--n);
                std::cout << "\tName: " << human.output_readable_name() << "\n\tAge: " << human.output_age() << "\n\t"
                          << (human.output_is_alive() ? "Living" : "Dead") << "\n\tPhone numbers:\n";
                for (auto&[key, value]: human.output_phone_numbers()) {
                    std::cout << "\t\t" << key << ": " << value << '\n';
                }
            } catch (std::out_of_range &) {
                std::cout << "No such person" << std::endl;
            }

        } else if (command == "delete") {
            auto humans = read_human_files();
            int n;
            std::cout << "Enter number of person to be shown > ";
            std::cin >> n;
            try {
                auto human = humans.at(--n);
                std::cout << "Are you sure you want to delete " << human.output_readable_name() << "? [y/n] > ";
                std::string input;
                std::cin >> input;
                if (input == "y") {
                    delete_human_file(human);
                    std::cout << "Deleted " << human.output_readable_name() << std::endl;
                } else {
                    std::cout << "Nothing was done." << std::endl;
                };

            } catch (std::out_of_range &) {
                std::cout << "No such person" << std::endl;
            }
        } else if (command == "help") {
            std::cout << commands_help << std::endl;

        } else if (command == "exit") { loop = false; }
    }

}
