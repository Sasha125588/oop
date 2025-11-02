#include <iostream>
#include <stdexcept>

using namespace std;

class Clock
{
private:
    int hours = 11;
    int minutes = 59;

    bool alarmEnabled;
    int alarmHours;
    int alarmMinutes;

    static void checkTimeFormat(int hours, int minutes)
        {
            if (hours < 0 || hours > 23)
                throw new invalid_argument(
                    "Hours must be between 0 and 23"
                );
            if (minutes < 0 || minutes > 59)
                throw new invalid_argument(
                    "Minutes must be between 0 and 59"
                );
        }

public:

    void setTime(int hours, int minutes)
    {
        checkTimeFormat(hours, minutes);

        this->hours = hours;
        this->minutes = minutes;
    }

    void setAlarm(int hours, int minutes)
    {
        checkTimeFormat(hours, minutes);

        alarmHours = hours;
        alarmMinutes = minutes;
        alarmEnabled = true;
    }

    void addMinute()
    {
        minutes++;
        if (minutes == 60)
        {
            minutes = 0;
            hours = (hours + 1) % 24;
        }

        if (alarmEnabled && hours == alarmHours && minutes == alarmMinutes)
        {
            cout << "ALARM!" << endl;
        }
    }

    void print24H()
    {
        cout << hours << ":" << minutes << endl;
    };

    void print12H()
    {
        int displayHours = (hours == 0 || hours == 12) ? 12 : hours % 12;
        cout << displayHours << ":" << minutes << (hours < 12 ? " AM" : " PM") << endl;
    }; // TODO: AM | PM
};