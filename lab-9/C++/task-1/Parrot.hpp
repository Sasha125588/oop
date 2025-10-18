#pragma once

#include "Animal.hpp"
#include <iostream>

using namespace std;

class Parrot : public Animal {
    private:
    string color;
    bool canTalk;

    public:
    Parrot(const string& name, int age, const string& color, bool canTalk)
        : Animal(name, age), color(color), canTalk(canTalk) {}

    string getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    bool getCanTalk() const { return canTalk; }
    void setCanTalk(bool canTalk) { this->canTalk = canTalk; }

    void sound() const override {
        if (canTalk) {
            cout << "Hello! Привіт!" << endl;
        } else {
            cout << "Squawk! Кря-кря!" << endl;
        }
    }

    void type() const override {
        cout << "Parrot" << endl;
    }

    void show() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() 
             << ", Color: " << color 
             << ", Can talk: " << (canTalk ? "Yes" : "No") << endl;
    }
};

