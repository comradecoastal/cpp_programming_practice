#include "Length.h"
#include <iostream>

int main() {
    Length width;
    Length height;
    width.set_value(100);
    width.set_to_inch();
    std::cout << width.get_value() << std::endl;
    height.set_to_inch();
    height.set_value(4);
    height.set_to_millimeter();
    std::cout << height.get_value() << std::endl;
    std::cout << (height + width) << std::endl;
    std::cout << (width + height) << std::endl;
}
