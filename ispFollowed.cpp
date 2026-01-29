#include <stdexcept>

using namespace std;

class Shape2D {
public:
    virtual double area() const = 0;
};
class Shape3D {
public:
    virtual double area() const = 0;
    virtual double volume() const = 0;
};


class Square : public Shape2D {
    double side;
public:
    Square(double s) : side(s) {}   
    double area() const override {
        return side * side;
    }
};

class Cube : public Shape3D {
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

