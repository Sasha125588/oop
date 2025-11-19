#pragma once

#include "Unit.hpp"

class Archer: public Unit {
    public:
    Archer(const string& name = "Archer")
        : Unit(name, 12, 4, 40) {}

    ~Archer() {
        cout << "🏹 Лучник склав зброю" << endl;
    }
};