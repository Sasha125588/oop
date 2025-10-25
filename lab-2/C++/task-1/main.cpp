#include "./Car.hpp"

void testCar();

class Rect
{
  int h, w;

public:
  Rect() { h = w = 10; }
  Rect(int h = 20, int w = 30) { this->h = h, this->w = w; }
  ~Rect() { cout << "a = " << "fixed" << endl; }
  // int ~Rect() {return h*w;} // Destructor cannot have a return type, Destructor cannot be redeclared
};

class Number
{
private:
  double num;

public:
  Number(int n) : num(n) {}
  void Show() { cout << num << endl; }
};

int main()
{
  //   Number a(12);
  //   a.Show();

  //   Number b(10);
  //   b.Show();

  testCar();

  return 0;
}

void testCar()
{
  cout << "\n=== Testing Car Class ===\n"
       << endl;

  cout << "1. Testing constructors:" << endl;
  cout << "\nDefault constructor (no parameters):" << endl;
  Car car1;
  cout << car1.printStats() << endl;

  cout << "\nTwo parameters (year, brand):" << endl;
  
  {
    Car car2(2020, "Toyota");
    cout << car2.printStats() << endl;
  }

  cout << "\nThree parameters (year, brand, maxSpeed):" << endl;
  Car car3(2018, "Toyota", 200);
  cout << car3.printStats() << endl;

  cout << "\nFour parameters (year, brand, maxSpeed, speed):" << endl;
  Car car4(2021, "Toyota", 200, 100);
  cout << car4.printStats() << endl;

  cout << "\n2. Testing different brands and years:" << endl;
  Car car5(2023, "BMW", 250, 0);
  cout << car5.printStats() << endl;

  Car car6(2022, "Mercedes", 220, 50);
  cout << car6.printStats() << endl;

  cout << "\nDestructors will be called automatically when cars go out of scope" << endl;
}
