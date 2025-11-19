#include "Shooter.hpp"

class Archer: virtual protected Shooter {
    protected:
        void Shoot() {
            if (Shooter::Shoot()) {
                cout << "Archer shoots with arrows!" << endl;
            }
        }
};