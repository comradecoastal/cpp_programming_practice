#include <iostream>
#include <iomanip>

int main() {

    std::string name, tmpInput;
    int price, temperature;
    bool hasCashback;
    bool readCashback = false;

    std::cout << "PLEASE ENTER PRODUCT DETAILS" << std::endl;\
    // input name variable
    std::cout << "Product's name: ";
    std::cin >> name;
    // input price variable
    std::cout << "Product's price: ";
    std::cin >> price;

    // input hasCashback variable
    while (!readCashback) {
        std::cout << "Is cash-back available for this product? (true/false) ";
        // read true/false as string
        std::cin >> tmpInput;
        if (tmpInput == "true") {
            hasCashback = true;
            readCashback = true;
        } else if (tmpInput == "false") {
            hasCashback = false;
            readCashback = true;
        } else {
            std::cout << "Invalid input format." << std::endl;
        }
    }
    // input temperature variable
    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;
    //output section
    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    //output width 25
    std::cout << name << '\n';
    std::cout << std::left << std::setw(17) << std::setfill('.') << "Price:"; // Price:.........
    std::cout << std::setw(8) << std::right << std::setfill('0') << std::uppercase << std::hex \
 << std::setprecision(8) << price << std::endl; // output price as capital hex with leading zeroes
    std::cout << "Has cash-back:" << std::setfill('.') << std::setw(11) << std::boolalpha << hasCashback << std::endl;
    std::cout << "Max temperature:" << std::setw(9) << std::dec << std::showpos << temperature << std::endl;

    return 0;
}