#include "./Fraction.hpp"

Fraction::Fraction() : Fraction(0) {}

Fraction::Fraction(int numerator) : Fraction(numerator, 1) {}

Fraction::Fraction(int numerator, int denominator)
{
  this->numerator = numerator;
  setDenominator(denominator);
}

Fraction &Fraction::reduce()
{
  int gcd = _gcd(abs(numerator), abs(denominator));

  numerator /= gcd;
  denominator /= gcd;

  return *this;
}

Fraction &Fraction::add(const Fraction &other)
{
  numerator = numerator * other.denominator + other.numerator * denominator;
  denominator *= other.denominator;
  
  return reduce();
}

Fraction &Fraction::add(int number)
{
  return add(*new Fraction(number));
}

Fraction &Fraction::subtract(const Fraction &other)
{
  numerator = numerator * other.denominator - other.numerator * denominator;
  denominator *= other.denominator;
  
  return reduce();
}

Fraction &Fraction::multiply(const Fraction &other)
{
  numerator *= other.numerator;
  denominator *= other.denominator;

  return reduce();
}

Fraction &Fraction::multiply(int number)
{
  return multiply(*new Fraction(number));
}

Fraction &Fraction::divide(const Fraction &other)
{
  if (other.numerator == 0) throw runtime_error("Attempted to divide by Zero\n");

  numerator *= other.denominator;
  denominator *= other.numerator;
  
  return reduce();        
}

bool Fraction::equals(const Fraction &other)
{
    Fraction f1 = (new Fraction(numerator, denominator))->reduce();
    Fraction f2 = (new Fraction(other.numerator, other.denominator))->reduce();

    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}

void Fraction::print() const
{
  if (denominator > 0)
  {
    cout << numerator << "/" << denominator << endl;
  }
  else
  {
    cout << numerator << endl;
  }
}