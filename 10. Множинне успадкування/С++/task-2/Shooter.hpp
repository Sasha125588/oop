#pragma once

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class Shooter {
    private:
        string ammunition_name;
        size_t ammunition_amount;

    protected:
        bool Shoot() {
            if (ammunition_amount == 0) {
                cout << "No ammunition left!" << endl;
                return false;
            }

            cout << "Ammunition name = " << ammunition_name << endl;
            ammunition_amount--;
            return true;
        }

        void setAmmunition(string ammunition_name, size_t ammunition_amount) {
            this->ammunition_name = ammunition_name;
            this->ammunition_amount = ammunition_amount;
        }

        size_t getAmmunitionAmount() const {
            return ammunition_amount;
        }
};