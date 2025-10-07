#pragma once

#include "Unit.hpp"

class Mage: public Unit {
    public:
    Mage(const string& name = "Mage")
        : Unit(name, 8, 10, 30) {}

    ~Mage() {
        cout << "🔮 Маг закінчив заклинання" << endl;
    }
};