#include "Shooter.hpp"

class Ranger: virtual protected Shooter {
    protected:
        void Shoot() {
            if (Shooter::Shoot()) {
                cout << "Ranger shoots with arrows!" << endl;
            }
        }
};