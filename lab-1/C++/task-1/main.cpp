#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Car
{
private:
    int yearModel;
    string brand;
    double speed;
    double maxSpeed;

public:
    int getYearModel() const
    {
        return yearModel;
    }

    string getBrand() const
    {
        return brand;
    }

    double getSpeed() const
    {
        return speed;
    }

    double getMaxSpeed() const
    {
        return maxSpeed;
    }

    void setYearModel(int year)
    {
        yearModel = year;
    }

    void setBrand(string newBrand)
    {
        brand = newBrand;
    }

    void setSpeed(double newSpeed)
    {
        speed = newSpeed;
    }

    void setMaxSpeed(double newMaxSpeed)
    {
        maxSpeed = newMaxSpeed;
    }

    void Accelerate(int value = 5)
    {
        if (speed + value <= maxSpeed)
            speed += value;
    }

    void Brake(int value = 5)
    {
        if (speed - value >= 0)
            speed -= value;
    }

    string printStatsBase()
    {
        string stats = "Year Model: " + to_string(yearModel) + "\nBrand: " + brand + "\nSpeed: " + to_string(speed) + "\nMax Speed: " + to_string(maxSpeed);

        return stats;
    }

    const string &printStatsConst()
    {
        string *stats = new string("Year Model: " + to_string(yearModel) + "\nBrand: " + brand + "\nSpeed: " + to_string(speed) + "\nMax Speed: " + to_string(maxSpeed));

        return *stats;
    }
};

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