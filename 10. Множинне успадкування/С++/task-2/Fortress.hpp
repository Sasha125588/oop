#include "ArcherTower.hpp"
#include "Catapult.hpp"

class Fortress: protected ArcherTower, protected Catapult {
    private:
        // double wall_thickness;        // товщина стін (метри)
        // short gate_health;           // стан воріт у відсотках (0-100)
        // size_t garrison_size;         // кількість гарнізону
        // string fortress_name;         // назва фортеці

    public:
        Fortress(string arrows_name, size_t arrows_amount,
                 string stones_name, size_t stones_amount
                //  double wall_thickness = 5.0, short gate_health = 100,
                //  size_t garrison_size = 100,
                //  string fortress_name = "Fortress"
                )
            // : wall_thickness(wall_thickness),
            //   gate_health(gate_health),
            //   garrison_size(garrison_size),
            //   fortress_name(fortress_name)
        {
            ArcherTower::setAmmunition(arrows_name, arrows_amount);
            Catapult::setAmmunition(stones_name, stones_amount);
        }

        void ArcherShoot() {
            ArcherTower::ArcherShoot();
        }

        void RangerShoot() {
            ArcherTower::RangerShoot();
        }

        void CatapultShoot() {
            Catapult::Shoot();
        }
};