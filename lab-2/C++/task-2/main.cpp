#include <iostream>

#include "Date.hpp"

using namespace std;

void testDate();

int main()
{
  testDate();

  return 0;
}

void testDate()
{
  cout << "\n=== Testing Date Class ===\n"
       << endl;
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
