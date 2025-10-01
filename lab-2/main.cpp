#include <iostream>
#include <map>
using namespace std;

void testCar();
void testDate();
void testFraction();

class Rect {
  int h, w;

public:
  Rect() { h = w = 10; }
  Rect(int h = 20, int w = 30) { this->h = h, this->w = w; }
  ~Rect() { cout << "a = " << "fixed" << endl; }
  // int ~Rect() {return h*w;} // Destructor cannot have a return type, Destructor cannot be redeclared
};

class Number {
private:
  double num;

public:
  Number(int n) : num(n) {}
  void Show() { cout << num << endl; }
};

class Car {
private:
  int year;
  string brand;
  double speed;
  double maxSpeed;

public:
  Car(int year, string brand, double maxSpeed, double speed) { // 4 parameters
    this->year = year;
    this->brand = brand;
    this->speed = speed;
    this->maxSpeed = maxSpeed;
    cout << "Car created 4 parameters" << endl;
  };
  Car(int year, string brand, double maxSpeed) { // 3 parameters
    this->year = year;
    this->brand = brand;
    this->speed = 0;
    this->maxSpeed = maxSpeed;
    cout << "Car created 3 parameters" << endl;
  };
  Car(int year, string brand) { // 2 parameters
    this->year = year;
    this->brand = brand;
    this->maxSpeed = 200;
    cout << "Car created 2 parameters" << endl;
  };
  Car() { // 0 parameters
    cout << "Car created default" << endl;
  };

  ~Car() { cout << "Car destroyed " << brand << " " << year << endl; }

  string printStats() {
    return "Year: " + to_string(year) + "\nBrand: " + brand +
           "\nSpeed: " + to_string(speed) +
           "\nMax Speed: " + to_string(maxSpeed);
  }
};

map<int, string> monthNames{
    {1, "January"},   {2, "February"}, {3, "March"},     {4, "April"},
    {5, "May"},       {6, "June"},     {7, "July"},      {8, "August"},
    {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}};

class Date {
private:
  int day;
  int month;
  int year;

  inline bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }

  int getDaysInMonth(int month, int year) {
    if (month < 1 || month > 12)
      return 0;

    if (month == 2) {
      return isLeapYear(year) ? 29 : 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
      return 30;
    }

    return 31;
  }

public:
  void setDay(int day) {
    int maxDays = getDaysInMonth(month, year);
    if (day > 0 && day <= maxDays) {
      this->day = day;
    } else {
      cout << "Invalid day" << endl;
    }
  }
  void setMonth(int month) {
    if (month > 0 && month <= 12) {
      this->month = month;
    } else {
      cout << "Invalid month" << endl;
    }
  }
  void setYear(int year) { this->year = year; }

  void printDate() {
    cout << day << "/"
         << (month >= 10 ? to_string(month) : "0" + to_string(month)) << "/"
         << year << endl;
  }
  void printDateMonthNameFull() {
    cout << day << " " << monthNames[month] << ", " << year << endl;
  }
  void printDateMonthNameShort() {
    cout << day << " " << monthNames[month].substr(0, 3) << " " << year << endl;
  }
};

namespace FractionScope {
#include "Fraction.h"
Fraction::Fraction() : Fraction(0) {}

Fraction::Fraction(int numerator) : Fraction(numerator, 1) {}

Fraction::Fraction(int numerator, int denominator) {
  this->numerator = numerator;
  setDenominator(denominator);
}

Fraction &Fraction::reduce() {
  int gcd = _gcd(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;
  return *this;
}

Fraction &Fraction::add(const Fraction &fraction) {
  numerator =
      numerator * fraction.denominator + fraction.numerator * denominator;
  denominator = denominator * fraction.denominator;
  reduce();
  return *this;
}

Fraction &Fraction::add(int number) {
  Fraction fraction(number);
  add(fraction);
  return *this;
}

Fraction &Fraction::subtract(const Fraction &fraction) {
  numerator = numerator * fraction.denominator - fraction.numerator * denominator;
  denominator = denominator * fraction.denominator;
  reduce();
  return *this;
}

Fraction &Fraction::multiply(const Fraction &fraction) {
  numerator = numerator * fraction.numerator;
  denominator = denominator * fraction.denominator;
  reduce();
  return *this;
}

Fraction &Fraction::multiply(int number) {
  numerator *= number;
  reduce();
  return *this;
}

Fraction &Fraction::divide(const Fraction &fraction) {
  numerator = numerator * fraction.denominator;
  denominator = denominator * fraction.numerator;
  reduce();
  return *this;
}

inline bool Fraction::equals(const Fraction &fraction) {
  return numerator == fraction.numerator && denominator == fraction.denominator;
}

void Fraction::print() const {
  cout << numerator << "/" << denominator << endl;
}
} // namespace FractionScope

int main() {
  // ======1======
  //   Number a(12);
  //   a.Show();

  //   Number b(10);
  //   b.Show();

  // ======2======
  // testCar();

  // ======3======
  // testDate();

  // ======4======
  testFraction();

  return 0;
}

void testCar() {
  cout << "\n=== Testing Car Class ===\n" << endl;
  
  cout << "1. Testing constructors:" << endl;
  cout << "\nDefault constructor (no parameters):" << endl;
  Car car1;
  cout << car1.printStats() << endl;
  
  cout << "\nTwo parameters (year, brand):" << endl;
  Car car2(2020, "Toyota");
  cout << car2.printStats() << endl;
  
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

void testDate() {
  cout << "\n=== Testing Date Class ===\n" << endl;
  Date date;

  cout << "1. Testing regular date:" << endl;
  date.setYear(2023);
  date.setMonth(10);
  date.setDay(15);
  cout << "Expected: 15/10/2023 in different formats:" << endl;
  date.printDate();
  date.printDateMonthNameFull();
  date.printDateMonthNameShort();

  cout << "\n2. Testing leap year (2024):" << endl;
  date.setYear(2024);
  date.setMonth(2);
  date.setDay(29);
  cout << "29th February 2024 (leap year) - should be valid:" << endl;
  date.printDate();
  date.printDateMonthNameFull();

  cout << "\n3. Testing non-leap year (2023):" << endl;
  date.setYear(2023);
  date.setMonth(2);
  cout << "Trying to set 29th February 2023 (non-leap year) - should show error:" << endl;
  date.setDay(29);

  cout << "\n4. Testing month boundaries:" << endl;
  date.setYear(2023);
  
  cout << "April (30 days):" << endl;
  date.setMonth(4);
  cout << "Setting day 30 (should work):" << endl;
  date.setDay(30);
  date.printDate();
  cout << "Setting day 31 (should show error):" << endl;
  date.setDay(31);

  cout << "\nDecember (31 days):" << endl;
  date.setMonth(12);
  cout << "Setting day 31 (should work):" << endl;
  date.setDay(31);
  date.printDate();

  cout << "\n5. Testing invalid inputs:" << endl;
  cout << "Setting month 13 (should show error):" << endl;
  date.setMonth(13);
  cout << "Setting day 32 (should show error):" << endl;
  date.setDay(32);
  cout << "Current date after invalid attempts:" << endl;
  date.printDateMonthNameFull();
}

void testFraction() {
  using namespace FractionScope;
  cout << "\n=== Testing Fraction Class ===\n" << endl;
  cout << "1. Testing constructors:" << endl;
  Fraction f1; // default constructor
  cout << "Default constructor: ";
  f1.print();

  Fraction f2(15); // single parameter
  cout << "Single parameter (15): ";
  f2.print();

  Fraction f3(10, 20); // two parameters
  cout << "Two parameters (10/20): ";
  f3.print();

  cout << "\n2. Testing reduction:" << endl;
  cout << "Before reduction (10/20): ";
  f3.print();
  f3.reduce();
  cout << "After reduction: ";
  f3.print();

  cout << "\n3. Testing arithmetic operations:" << endl;
  Fraction a(1, 2); // 1/2
  Fraction b(1, 3); // 1/3

  cout << "a = ";
  a.print();
  cout << "b = ";
  b.print();

  // Addition
  Fraction sum = a;
  sum.add(b);
  cout << "a + b = ";
  sum.print();

  // Subtraction
  Fraction diff = a;
  diff.subtract(b);
  cout << "a - b = ";
  diff.print();

  // Multiplication
  Fraction prod = a;
  prod.multiply(b);
  cout << "a * b = ";
  prod.print();

  // Division
  Fraction quot = a;
  quot.divide(b);
  cout << "a / b = ";
  quot.print();

  cout << "\n4. Testing operations with integers:" << endl;
  Fraction c(1, 2);
  cout << "c = ";
  c.print();

  c.add(3);
  cout << "c + 3 = ";
  c.print();

  c.multiply(2);
  cout << "Result * 2 = ";
  c.print();

  cout << "\n5. Testing comparison:" << endl;
  Fraction d1(1, 2);
  Fraction d2(2, 4);
  Fraction d3(3, 4);

  
  cout << "Comparing ";
  d1.print();
  cout << "and ";
  d2.print();
  d2.reduce(); // This will reduce 2/4 to 1/2
  cout << "Result: " << (d1.equals(d2) ? "Equal" : "Not equal") << endl;

  cout << "Comparing ";
  d1.print();
  cout << "and ";
  d3.print();
  cout << "Result: " << (d1.equals(d3) ? "Equal" : "Not equal") << endl;
}