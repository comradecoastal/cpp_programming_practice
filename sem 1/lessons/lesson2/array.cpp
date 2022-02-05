#include <iostream>

int main() {
//    int numbers[5];
//    for (int i = 0; i < sizeof(numbers) / 4; i++) {
//        numbers[i] = i * i;
//    }
//    for (int i = 0; i < sizeof(numbers) / 4; i++) {
//        std::cout << numbers[i] << std::endl;
//    }

    // Память не пустая
    int* numbers = new int[5];
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << std::endl;
    }

    // Освобождение памяти
    delete[] numbers;
}

