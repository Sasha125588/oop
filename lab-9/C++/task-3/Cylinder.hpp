#pragma once

#include <iostream>
#include "Circle.hpp"

using namespace std;

class Cylinder : public Circle {
private:
    double height;

public:
    Cylinder(double x, double y, double z, double radius, double height) 
        : Circle(x, y, z, radius), height(height) {}

    double getHeight() const { return height; }
    void setHeight(double h) { height = h; }

    double area() const override {
        // Повна площа поверхні = 2πr² (два кола) + 2πrh (бічна поверхня)
        double radius = getRadius();
        return 2 * M_PI * radius * radius + 2 * M_PI * radius * height;
    }

    double volume() const override {
        // Об'єм циліндра = πr²h
        double radius = getRadius();
        return M_PI * radius * radius * height;
    }

    void printShapeName() const override {
        cout << "Cylinder";
    }

    void print() const override {
        Circle::print();
        cout << "Height: " << height << endl;
        cout << "Cylinder Area: " << area() << endl;
        cout << "Cylinder Volume: " << volume() << endl;
    }
};