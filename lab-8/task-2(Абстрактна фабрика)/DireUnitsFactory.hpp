#pragma once

#include "UnitsFactory.hpp"
#include "Archer.hpp"
#include "Mage.hpp"
#include "Swordsman.hpp"
#include <string>

class DireUnitsFactory : public UnitsFactory {
    private:
    const string prefix = "Dire";

    public:
    Swordsman* CreateSwordsman(int number) const override {
        string name = prefix + " #" + to_string(number);
        Swordsman* swordsman = new Swordsman(name);
        return swordsman;
    }
    Archer* CreateArcher(int number) const override {
        string name = prefix + " #" + to_string(number);
        Archer* archer = new Archer(name);
        return archer;
    }
    Mage* CreateMage(int number) const override {
        string name = prefix + " #" + to_string(number);
        Mage* mage = new Mage(name);
        return mage;
    }

        
};