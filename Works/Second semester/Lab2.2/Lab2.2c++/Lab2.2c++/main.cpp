#include <iostream>
#include "Shapes.h"

void printShapeInfo(const Shapes& shape) {
    std::cout << "Area: " << shape.calculateArea()
        << ", Perimeter: " << shape.calculatePerimeter() << std::endl;
}

int main() {
    Circle circle(5.0);
    Ellipse ellipse(5.0, 3.0);

    std::cout << "Circle info:" << std::endl;
    printShapeInfo(circle);

    std::cout << "\nEllipse info:" << std::endl;
    printShapeInfo(ellipse);

    return 0;
}