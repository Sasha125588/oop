#pragma once

#include "Archer.hpp"
#include "Mage.hpp"
#include "Swordsman.hpp"

class UnitsFactory {
    public:
        virtual ~UnitsFactory() = default;

        virtual Swordsman* CreateSwordsman(int number) const = 0;
        virtual Archer* CreateArcher(int number) const = 0;
        virtual Mage* CreateMage(int number) const = 0;
};