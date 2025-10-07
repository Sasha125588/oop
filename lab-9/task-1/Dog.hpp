#pragma once

#include "Animal.hpp"
#include <iostream>

using namespace std;

class Dog : public Animal {
    private:
    string breed;
    string color;

    public:
    Dog(const string& name, int age, const string& breed, const string& color)
        : Animal(name, age), breed(breed), color(color) {}

    string getBreed() const { return breed; }
    void setBreed(const string& breed) { this->breed = breed; }

    string getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    void sound() const override {
        cout << "Woof! Гав-гав!" << endl;
    }

    void type() const override {
        cout << "Dog" << endl;
    }

    void show() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() 
             << ", Breed: " << breed << ", Color: " << color << endl;
    }
};

