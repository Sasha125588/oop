#include "Fraction.hpp"

using namespace std;

void testFraction();

int main()
{
  testFraction();

  return 0;
}

void testFraction()
{
  cout << "\n=== Testing Fraction Class ===\n"
       << endl;
  cout << "1. Testing constructors:" << endl;
  Fraction f1; // default constructor
  cout << "Default constructor: ";
  f1.print();

  Fraction f2(15); // single parameter
  cout << "Single parameter (15): ";
  f2.print();

  cout << "Two parameters (10/-2): " << endl;
  Fraction f3(10, -2); // two parameters

  f3.print();

  cout << "\n2. Testing reduction:" << endl;
  cout << "Before reduction (10/-2): ";
  f3.print();
  f3.reduce();
  cout << "After reduction: ";
  f3.print();

  f3.add(1);
  cout << "Add 1: ";
  f3.print();

  f3.subtract(2);
  cout << "Subtract 2: ";
  f3.print();

  f3.multiply(3);
  cout << "Multiply 3: ";
  f3.print();

  cout << "\n2. Testing division by zero(1/0):" << endl;
  Fraction f4(1, 0);
  cout << "Division by zero: ";
  f4.print();

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