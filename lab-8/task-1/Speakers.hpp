#pragma once

#include "Device.hpp"
#include <iostream>

class Speakers: public Device {
    private:
    int volume;

    public:
    Speakers() = default;
    Speakers(const string& name, bool isTurn, int volume = 25): Device(name, isTurn), volume(volume){
        cout << "Constructor Speakers: гучність " << volume << endl;
    }

    ~Speakers() {
        cout << "Destructor Speakers: гучність " << volume << endl;
    }

    void increaseVolume() {
        volume++;
        cout << "Гучність збільшено до " << volume << endl;
    } 
    
    void decreaseVolume() {
        volume--;
        cout << "Гучність зменшено до " << volume << endl;
    }

    int getVolume() const { return volume; }
};