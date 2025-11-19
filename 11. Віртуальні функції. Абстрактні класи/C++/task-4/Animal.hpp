#pragma once

#include <iostream>

using namespace std;

class Animal {
    private:
    string name;
    int age;

    public:
    Animal(const string& name, int age): name(name), age(age){}
    
    virtual ~Animal() {}

    string getName() const {return name;}
    void setName(const string& name) { this->name = name; }

    int getAge() const { return age;}
    void setAge(int age) { this->age = age; }

    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
