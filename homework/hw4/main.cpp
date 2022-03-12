#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path path("../Humans");
    std::cout << fs::exists(path);
    fs::create_directory(path);

    fs::path filepath = path / "human.json";
    std::fstream fout(filepath, std::ios::out);
    fout << "googog gagaga boobs\n";
    fout << "boobs";
    fout.close();

    std::fstream fin(filepath, std::ios::in);
    for(std::string line; std::getline(fin, line);) {
        std::cout << line << std::endl;
    }
    fin.close()

}
