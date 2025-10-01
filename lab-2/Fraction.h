#pragma once

#include <iostream>

using namespace std;

class Fraction {
private:
  int numerator;
  int denominator;

  int _gcd(int a, int b) { // a = 10 b = 20 |=> a = 20, b = 10 |=> a = 10, b = 0 |=> return a
    if (b == 0) return a;
    return _gcd(b, a % b);
  }

public:
  Fraction();
  Fraction(int numerator);
  Fraction(int numerator, int denominator);

  int getNumerator() const { return numerator; }
  void setNumerator(int numerator) { this->numerator = numerator; }
  
  int getDenominator() const { return denominator; }
  void setDenominator(int denominator) {
    if (denominator == 0 || denominator < 0) {
      cout << "Invalid denominator" << endl;
      denominator = 1;
    }
    this->denominator = denominator;
  }

  Fraction &reduce();
  Fraction &add(const Fraction &fraction);
  Fraction &add(int number);
  Fraction &subtract(const Fraction &fraction);
  Fraction &multiply(const Fraction &fraction);
  Fraction &multiply(int number);
  Fraction &divide(const Fraction &fraction);
  bool equals(const Fraction &fraction);
  void print() const;
};