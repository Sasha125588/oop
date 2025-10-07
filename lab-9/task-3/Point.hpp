#pragma once

#include <iostream>
#include "Shape.hpp"

using namespace std;

class Point : public Shape {
    private:
        double x, y, z;
    public:
        Point(double x, double y, double z) : x(x), y(y), z(z) {}
        
        void printShapeName() const override {
            cout << "Point";
        }
        
        void print() const override {
            cout << "Coordinates: (" << x << ", " << y << ", " << z << ")" << endl;
            cout << "Area: " << area() << endl;
            cout << "Volume: " << volume() << endl;
        }
    };