#include <iostream>
#include <iomanip>
#include <windows.h>

#define CHARGE 3e9
#define INTENSITY 3,3e-5
#define POTENTIAL 3,3e-2
#define CURRENT 3e9


int main() {
    // help from stackoverflow
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int conversionMode, conversion; // mode of conversion, and unit of conversion
    double value, convCoefficient; // value to be converted, and coefficient used for conversion
    std::string convText1, convText2; // text units

    // choose conversion mode
    std::cout << "КОНВЕРТОР СГС -- СИ" << std::endl;
    std::cout << "Выберите реэим работы [1: СИ -> СГС/2: СГС -> СИ]: ";
    std::cin >> conversionMode;

    // choose conversion unit
    if (conversionMode == 1) {
        std::cout << "Какой перевод вы желаете выполнить?\n"
                  << "1: Заряд (Кл -> ед.зар.)\n"
                  << "2: Напряжённость поля (В/м -> ед.напр.)\n"
                  << "3: Электрический потенциал (В -> ед.пот.)\n"
                  << "4: Сила тока (А -> ед.с.т.)\nввод: ";
    } else {
        std::cout << "Какой перевод вы желаете выполнить?\n"
                  << "1: Заряд (ед.зар. -> Кл)\n"
                  << "2: Напряжённость поля (ед.напр. -> В/м)\n"
                  << "3: Электрический потенциал (ед.пот. -> В)\n"
                  << "4: Сила тока (ед.с.т. -> А)\nввод: ";
    }
    std::cin >> conversion;

    // input value to be converted
    std::cout << "Введите значение: ";
    std::cin >> value;

    // set output mode to scientific with 4 digits after 0
    std::cout << std::scientific << std::setprecision(4);

    // setting important variables
    switch (conversion) {
        case 1:
            convCoefficient = CHARGE;
            convText1 = "Кл";
            convText2 = "ед.зар.";
            break;
        case 2:
            convCoefficient = INTENSITY;
            convText1 = "В/м";
            convText2 = "ед.напр.";
            break;
        case 3:
            convCoefficient = POTENTIAL;
            convText1 = "В";
            convText2 = "ед.пот.";
            break;
        case 4:
            convCoefficient = CURRENT;
            convText1 = "А";
            convText2 = "ед.с.т.";
            break;
    }

    // conversion + output
    if (conversionMode == 1) {
        std::cout << value << convText1 << " = " << value * convCoefficient << convText2 << std::endl;
    } else {
        std::cout << value << convText2 << " = " << value / convCoefficient << convText1 << std::endl;
    }


    return 0;
}