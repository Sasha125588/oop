#include <iostream>
#include "Fortress.hpp"
using namespace std;

int main()
{
    Fortress fortress("Arrows", 4, "Stones", 10);

    cout << "Archer shooting 3 times:" << endl;
    fortress.ArcherShoot();
    fortress.ArcherShoot();
    fortress.ArcherShoot();

    cout << "\nRanger shooting 2 times:" << endl;
    fortress.RangerShoot();
    fortress.RangerShoot();

    cout << "\nCatapult shooting 1 time:" << endl;
    fortress.CatapultShoot();

    system("pause");
    return 0;
}
