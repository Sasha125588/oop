#pragma once

#include <iostream>

using namespace std;

class Animal {
    private:
    string name;
    int age;

    public:
    Animal(const string& name, int age): name(name), age(age){}

    string getName() const {return name;}
    void setName(const string& name) { this->name = name; }

    int getAge() const { return age;}
    void setAge(int age) { this->age = age; }

    virtual void sound() const {
        cout << "Animal sound" << endl;
    };
    virtual void type() const {
        cout << "Animal" << endl;
    };
    virtual void show() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};