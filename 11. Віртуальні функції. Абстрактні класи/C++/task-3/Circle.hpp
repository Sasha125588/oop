#pragma once

#include <iostream>
#include "Point.hpp"

using namespace std;

class Circle : public Point {
private:
    double radius;

public:
    Circle(double x, double y, double z, double radius) 
        : Point(x, y, z), radius(radius) {}

    double getRadius() const { return radius; }
    void setRadius(double r) { radius = r; }

    double area() const override {
        return M_PI * radius * radius;
    }

    void printShapeName() const override {
        cout << "Circle";
    }

    void print() const override {
        Point::print();
        cout << "Radius: " << radius << endl;
        cout << "Circle Area: " << area() << endl;
        cout << "Circle Volume: " << volume() << endl;
    }
};