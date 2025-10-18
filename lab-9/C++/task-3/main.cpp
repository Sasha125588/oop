#include <iostream>
#include <vector>
#include "Shape.hpp"
#include "Point.hpp"
#include "Circle.hpp"
#include "Cylinder.hpp"

using namespace std;

void printSeparator();
void testPolymorphism();

int main()
{
    testPolymorphism();

    return 0;
}

void printSeparator() {
    cout << string(60, '-') << endl;
}

void testPolymorphism() {
    cout << "\n╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║         ТЕСТ ГЕОМЕТРИЧНИХ ФІГУР (ПОЛІМОРФІЗМ)             ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝\n" << endl;

    vector<Shape*> shapes = {
        new Point(0, 0, 0),
        new Point(5, 10, 15),
        new Circle(0, 0, 0, 5),
        new Circle(10, 20, 0, 7.5),
        new Cylinder(0, 0, 0, 3, 10),
        new Cylinder(5, 5, 5, 4, 8),
        new Cylinder(0, 0, 0, 2.5, 12)
    };

    cout << "Всього фігур у масиві: " << shapes.size() << "\n" << endl;

    int count = 1;
    for (auto shape : shapes) {
        printSeparator();
        cout << "Фігура #" << count << ": ";
        shape->printShapeName();
        cout << endl;
        printSeparator();
        
        shape->print();
        
        cout << "\n📐 Площа поверхні: " << shape->area() << endl;
        cout << "📦 Об'єм: " << shape->volume() << endl;
        
        printSeparator();
        cout << endl;
        count++;
    }

    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                   ТЕСТ ЗАВЕРШЕНО!                          ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝\n" << endl;

    for (auto shape : shapes) {
        delete shape;
    }
}
