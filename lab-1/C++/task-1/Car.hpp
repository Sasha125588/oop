#include <string>
#include <stdexcept>
#include <algorithm>

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
        if (year < 1885)
        {
            throw invalid_argument("Перша машина зʼявилася в 1885 році.");
        }
        yearModel = year;
    }

    void setBrand(string newBrand)
    {
        brand = newBrand;
    }

    void setSpeed(double newSpeed)
    {
        if (newSpeed > maxSpeed)
        {
            throw invalid_argument("Швидкість не може бути більше максимальної.");
        }
        speed = max(0.0, newSpeed);
    }

    void setMaxSpeed(double newMaxSpeed)
    {
        maxSpeed = max(0.0, newMaxSpeed);
        if (speed > maxSpeed)
        {
            speed = maxSpeed;
        }
    }

    void Accelerate(int value = 5)
    {
        speed = min(maxSpeed, speed + value);
    }

    void Brake(int value = 5)
    {
        speed = max(0.0, speed - value);
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