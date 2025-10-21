#include <iostream>

using namespace std;

class Car
{
private:
  int year;
  string brand;
  double speed;
  double maxSpeed;

public:
  Car(int year, string brand, double maxSpeed, double speed)
  { // 4 parameters
    this->year = year;
    this->brand = brand;
    this->speed = speed;
    this->maxSpeed = maxSpeed;
    cout << "Car created 4 parameters" << endl;
  };
  Car(int year, string brand, double maxSpeed)
  { // 3 parameters
    this->year = year;
    this->brand = brand;
    this->speed = 0;
    this->maxSpeed = maxSpeed;
    cout << "Car created 3 parameters" << endl;
  };
  Car(int year, string brand)
  { // 2 parameters
    this->year = year;
    this->brand = brand;
    this->maxSpeed = 200;
    cout << "Car created 2 parameters" << endl;
  };
  Car()
  { // 0 parameters
    cout << "Car created default" << endl;
  };

  ~Car() { cout << "Car destroyed " << brand << " " << year << endl; }

  string printStats()
  {
    return "Year: " + to_string(year) + "\nBrand: " + brand +
           "\nSpeed: " + to_string(speed) +
           "\nMax Speed: " + to_string(maxSpeed);
  }
};