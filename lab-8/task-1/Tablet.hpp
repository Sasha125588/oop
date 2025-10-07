#pragma once

#include "Device.hpp"
#include <iostream>

class Tablet: public Device {
    private:
    double screenSize;

    public:
    Tablet() = default;
    Tablet(const string& name, bool isTurn, double screenSize = 13.3): Device(name, isTurn), screenSize(screenSize){
        cout << "Constructor Tablet: розмір екрану " << screenSize << " дюймів" << endl;
    }

    ~Tablet() {
        cout << "Destructor Tablet: розмір екрану " << screenSize << " дюймів" << endl;
    }

    void displayInfo() const {
        cout << "Інформація про екран: розмір = " << screenSize << " дюймів" << endl;
    }

    double getScreenSize() const { return screenSize; }
};