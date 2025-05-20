#pragma once

class Shapes {
public:
    virtual ~Shapes() = default;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
};

class Ellipse : public Shapes {
private:
    double semiMajorAxis;
    double semiMinorAxis;

public:
    Ellipse(double major, double minor);
    double getSemiMajorAxis() const;
    double getSemiMinorAxis() const;
    double calculateArea() const override;
    double calculatePerimeter() const override;
};

class Circle : public Shapes {
private:
    double radius;

public:
    explicit Circle(double r);
    double getRadius() const;
    double calculateArea() const override;
    double calculatePerimeter() const override;
};