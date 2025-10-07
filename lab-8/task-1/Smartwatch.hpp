#pragma once

#include "Device.hpp"
#include <iostream>


class Smartwatch: public Device {
    private:
    int heartRateSensor;  

    public:
    Smartwatch() = default;
    Smartwatch(const string& name, bool isTurn, int heartRateSensor = 100): Device(name, isTurn), heartRateSensor(heartRateSensor){
        cout << "Constructor Smartwatch: пульс " << heartRateSensor << " уд/хв" << endl;
    }

    ~Smartwatch() {
        cout << "Destructor Smartwatch: пульс " << heartRateSensor << " уд/хв" << endl;
    }
    
    void monitorHeartRate() const {
        cout << "Моніторинг пульсу: " << heartRateSensor << " уд/хв" << endl;
    }

    int getHeartRate() const { return heartRateSensor; }
};