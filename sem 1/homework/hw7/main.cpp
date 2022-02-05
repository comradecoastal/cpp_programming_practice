#include "Shapes.h"

int main() {
    Shapes::Shape shape;
    Shapes::Ellipse ellipse(1, 3, {2, -1});
    Shapes::Circle circle(4, {0, 1});
    Shapes::Polygon polygon({{1, 1}, {2, 3}, {2, 4}, {0, 5}, {-1, 3}});
    Shapes::Rectangle rectangle(3, 4, {3, 3});
    Shapes::Square square(3, {3, 3});
    Shapes::Triangle triangle({{1, 2}, {3, 4}, {0, 3}});

    std::vector<Shapes::Shape*> array_of_shapes;
    array_of_shapes.push_back(&shape);
    array_of_shapes.push_back(&ellipse);
    array_of_shapes.push_back(&circle);
    array_of_shapes.push_back(&polygon);
    array_of_shapes.push_back(&rectangle);
    array_of_shapes.push_back(&square);
    array_of_shapes.push_back(&triangle);

    for (auto & elem : array_of_shapes) {
        elem->print_info();
        std::cout << "Area: " << elem->get_area() << ", Perimeter: " << elem->get_perimeter() << '\n' << std::endl;
    }

    ellipse.set_axes(4, 5);
    circle.set_diameter(2);
    polygon.set_vertex(4, {-2, 2});
    rectangle.set_sides(4, 3);
    square.set_side(5);
    triangle.set_vertex(1, {0, 0});

    for (auto & elem : array_of_shapes) {
        elem->print_info();
        std::cout << "Area: " << elem->get_area() << ", Perimeter: " << elem->get_perimeter() << '\n' << std::endl;
    }


}

