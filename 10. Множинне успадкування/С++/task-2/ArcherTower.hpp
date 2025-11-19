#include "Archer.hpp"
#include "Ranger.hpp"

class ArcherTower: protected Archer, protected Ranger {
    protected:
        void ArcherShoot() {
            Archer::Shoot();
        }

        void RangerShoot() {
            Ranger::Shoot();
        }
};