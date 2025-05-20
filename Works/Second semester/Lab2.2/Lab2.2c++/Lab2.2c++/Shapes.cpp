#include "Shapes.h"
#include <cmath>


constexpr double PI = 3.14159265358979323846;

Ellipse::Ellipse(double major, double minor)
    : semiMajorAxis(major), semiMinorAxis(minor) {
}

double Ellipse::getSemiMajorAxis() const {
    return semiMajorAxis;
}

double Ellipse::getSemiMinorAxis() const {
    return semiMinorAxis;
}

double Ellipse::calculateArea() const {
    return PI * semiMajorAxis * semiMinorAxis; 
}

double Ellipse::calculatePerimeter() const {
    return PI * (3 * (semiMajorAxis + semiMinorAxis) -
        sqrt((3 * semiMajorAxis + semiMinorAxis) *
            (semiMajorAxis + 3 * semiMinorAxis)));
}

Circle::Circle(double r) : radius(r) {}

double Circle::getRadius() const {
    return radius;
}

double Circle::calculateArea() const {
    return PI * radius * radius;
}

double Circle::calculatePerimeter() const {
    return 2 * PI * radius;
}