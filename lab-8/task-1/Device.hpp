#pragma once

#include <iostream>
#include <string>

using namespace std;

class Device {
    private:
    string name;
    bool isTurn;

    public:
    Device() = default;
    Device(const string& name, bool isTurn = false): name(name), isTurn(isTurn){
        cout << "Constructor Device: " << name << " створено" << endl;
    }

    ~Device() {
        cout << "Destructor Device: " << name << " знищено" << endl;
    }

    void turnOn() {
        isTurn = true;
        cout << name << " увімкнено" << endl;
    }
    
    void turnOff() {
        isTurn = false;
        cout << name << " вимкнено" << endl;
    }

    string getName() const { return name; }
    bool getIsTurn() const { return isTurn; }
};

