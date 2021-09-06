#include <iostream>
#include <windows.h>

#define CHARGE 3e9
#define INTENSITY 3,3e-5
#define POTENTIAL 3,3e-2
#define CURRENT 3e9


int main() {
//    setlocale(LC_ALL, "");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int conversionMode, conversion;
    double value;

    std::cout << "КОНВЕРТОР СГС -- СИ" << std::endl;
    std::cout << "Выберите реэим работы [1: СИ -> СГС/2: СГС -> СИ]: ";
    std::cin >> conversionMode;

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

    std::cout << "Введите значение: ";
    std::cin >> value;

    switch (conversion) {
        case 1:
            std::cout << value << " = " << ((conversionMode == 1) ? value * CHARGE : value / CHARGE);
            break;
        case 2:
            std::cout << value << " = " << ((conversionMode == 1) ? value * INTENSITY : value / INTENSITY);
            break;
        case 3:
            std::cout << value << " = " << ((conversionMode == 1) ? value * POTENTIAL : value / POTENTIAL);
            break;
        case 4:
            std::cout << value << " = " << ((conversionMode == 1) ? value * CURRENT : value / CURRENT);
            break;
    }


    return 0;
}