#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &line, char splitChar = ' ') {
    /**
     * Function splits a sting into a vector of strings along specified character
     *
     * @param line string that is being split
     * @param spitChar character to be split along
     * @return vector of strings
     */

    std::vector<std::string> array; // output vector
    std::string tmpString;
    int pos = 0;
    int posNew; // position variables
    int len = line.size(); // length of input string

    // cycle breaks when no more ' ' is found (posNew == -1)
    while (pos > -1) {
        posNew = line.find(splitChar, pos); // search for ' ' starting from pos position
//        std::cout << posNew << std::endl;
        if (posNew != -1) { // test if ' ' was found
            tmpString = line.substr(pos, posNew - pos);
            pos = posNew + 1; // pos is now put after the ' ' that has been found
        } else {
            tmpString = line.substr(pos, len - pos);
            pos = -1; // condition to exit cycle
        }

        // test that tmpString is not empty
        if (tmpString.length() > 0) {
            array.push_back(tmpString);
        }

    }

    return array;
}

int main() {
    char splitChar;
    std::string line;
    std::vector<std::string> array;

    std::cout << "Enter line:" << std::endl;
    std::getline(std::cin, line);

    std::cout << "Enter character: ";
    std::cin >> splitChar;
    std::cout << std::endl;

    auto output = split(line, splitChar);
    for (auto word: output) {
        std::cout << '"' << word << '"' << std::endl;
    }

}