#include "Shooter.hpp"

class Catapult: protected Shooter {
    protected:
        void Shoot() {
            if (Shooter::Shoot()) {
                cout << "Catapult shoots with stones!" << endl;
            }
        }
};