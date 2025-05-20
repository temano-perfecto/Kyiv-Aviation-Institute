#include "ExpressionCalculator.h"

ExpressionCalculator::ExpressionCalculator(double a, double c, double d) : a(a), c(c), d(d) {}

void ExpressionCalculator::setA(double value) { a = value; }
void ExpressionCalculator::setC(double value) { c = value; }
void ExpressionCalculator::setD(double value) { d = value; }

double ExpressionCalculator::getA() const { return a; }
double ExpressionCalculator::getC() const { return c; }
double ExpressionCalculator::getD() const { return d; }

double ExpressionCalculator::calculate() const {
    if (d == 0) {
        throw std::invalid_argument("Division by zero in sqrt(42/d) - d cannot be zero");
    }

    if (42.0 / d < 0) {
        throw std::invalid_argument("Square root of negative number in sqrt(42/d)");
    }

    double denominator = c + a - 1;
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero in denominator (c + a - 1)");
    }

    double numerator = 2 * c - d * sqrt(42.0 / d);
    return numerator / denominator;
}