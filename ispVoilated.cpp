#include <stdexcept>


class Shape {
public:
    virtual double area() const = 0;
    virtual double volume() const = 0;
};


class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}   
    double area() const override {
        return side * side;
    }
    double volume() const override {
        throw std::logic_error("Volume not applicable for Square");
    }
};

class Cube : public Shape {
    double side;
public:
    Cube(double s) : side(s) {}
    double area() const override {
        return 6 * side * side;
    }
    double volume() const override {
        return side * side * side;
    }
};

