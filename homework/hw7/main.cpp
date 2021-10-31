#include "Shapes.h"

int main() {
    Shapes::Shape shape;
    Shapes::Ellipse ellipse;
    Shapes::Circle circle;
    Shapes::Polygon polygon;
    Shapes::Rectangle rectangle;
    Shapes::Square square;
    Shapes::Triangle triangle;

//    std::cout << shape.get_area() << " " << shape.get_perimeter() << std::endl;
//    shape.print_info();
    std::cout << line.get_area() << " " << line.get_perimeter() << std::endl;
    line.print_info();
    std::cout << rectangle.get_area() << ' ' << rectangle.get_perimeter() << std::endl;
    rectangle.print_info();
//    std::cout << ellipse.get_area() << " " << ellipse.get_perimeter() << std::endl;
//    ellipse.print_info();
}

