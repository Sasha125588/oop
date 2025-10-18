#include <map>
#include <iostream>

using namespace std;

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
