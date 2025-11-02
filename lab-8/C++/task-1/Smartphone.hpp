#pragma once

#include "Device.hpp"
#include <iostream>

class Smartphone: public Device {
    private:
    string phoneNumber;

    public:
    Smartphone() = default;
    Smartphone(const string& name, bool isTurn, const string& phoneNumber): Device(name, isTurn), phoneNumber(phoneNumber){
        cout << "Constructor Smartphone: номер " << phoneNumber << endl;
    }

    ~Smartphone() {
        cout << "Destructor Smartphone: номер " << phoneNumber << endl;
    }

    void makeCall() const {
        cout << "Здійснюється дзвінок з номера " << phoneNumber << endl;
    }

    string getPhoneNumber() const { return phoneNumber; }
};
