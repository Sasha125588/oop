#pragma once

#include "Animal.hpp"
#include <iostream>

using namespace std;

class Hamster : public Animal {
    private:
    string color;
    string furLength; // short, medium, long

    public:
    Hamster(const string& name, int age, const string& color, const string& furLength)
        : Animal(name, age), color(color), furLength(furLength) {}

    string getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    string getFurLength() const { return furLength; }
    void setFurLength(const string& furLength) { this->furLength = furLength; }

    void sound() const override {
        cout << "Squeak! Пі-пі!" << endl;
    }

    void type() const override {
        cout << "Hamster" << endl;
    }

    void show() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() 
             << ", Color: " << color << ", Fur length: " << furLength << endl;
    }
};

