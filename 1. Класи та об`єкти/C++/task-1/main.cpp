#include <iostream>
#include <chrono>

#include "./Car.hpp"

using namespace std;

int main()
{
    Car car;

    // 1 //

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < 3000000; i++)
    {
        car.printStatsBase();
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Time taken 1: " << duration.count() << " milliseconds" << endl;

    // 2 //

    auto start2 = chrono::high_resolution_clock::now();

    for (int i = 0; i < 3000000; i++)
    {
        car.printStatsConst();
    }

    auto end2 = chrono::high_resolution_clock::now();

    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    cout << "Time taken 2: " << duration2.count() << " milliseconds" << endl;

    return 0;
}