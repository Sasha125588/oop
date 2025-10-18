#include <iostream>
#include <map>
using namespace std;

void testDate();

map<int, string> monthNames{
    {1, "January"}, {2, "February"}, {3, "March"}, {4, "April"}, {5, "May"}, {6, "June"}, {7, "July"}, {8, "August"}, {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}};

class Date
{
private:
  int day;
  int month;
  int year;

  inline bool isLeapYear(int year)
  {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }

  int getDaysInMonth(int month, int year)
  {
    if (month < 1 || month > 12)
      return 0;

    if (month == 2)
    {
      return isLeapYear(year) ? 29 : 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
      return 30;
    }

    return 31;
  }

public:
  void setDay(int day)
  {
    int maxDays = getDaysInMonth(month, year);
    if (day > 0 && day <= maxDays)
    {
      this->day = day;
    }
    else
    {
      cout << "Invalid day" << endl;
    }
  }
  void setMonth(int month)
  {
    if (month > 0 && month <= 12)
    {
      this->month = month;
    }
    else
    {
      cout << "Invalid month" << endl;
    }
  }
  void setYear(int year) { this->year = year; }

  void printDate()
  {
    cout << day << "/"
         << (month >= 10 ? to_string(month) : "0" + to_string(month)) << "/"
         << year << endl;
  }
  void printDateMonthNameFull()
  {
    cout << day << " " << monthNames[month] << ", " << year << endl;
  }
  void printDateMonthNameShort()
  {
    cout << day << " " << monthNames[month].substr(0, 3) << " " << year << endl;
  }
};

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
