#pragma once

#include "Unit.hpp"

class Swordsman: public Unit {
    public:
    Swordsman(const string& name = "Swordsman")
        : Unit(name, 15, 5, 60) {}

    ~Swordsman() {
        cout << "🗡️ Мечник відступив" << endl;
    }
};