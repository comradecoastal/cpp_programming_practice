#include <iostream>

int main() {
    int x = 5;
    int y = 6;
    int z = 7;
    int* address_of_x = &x;
    std::cout << *(address_of_x) << std::endl;
    address_of_x++;
    std::cout << *(address_of_x) << std::endl;
    std::cout << *(address_of_x += 4) << std::endl;
    std::cout << *(address_of_x -= 4) << std::endl;

//    std::cout << address_of_x;
//    char* first_byte = (char *)(address_of_x);
//    std::cout << address_of_x << ' ' << *address_of_x << std::endl;
//    std::cout << *first_byte;
}
