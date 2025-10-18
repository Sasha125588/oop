#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Clock
{
private:
    int hours = 15;
    int minutes = 59;

public:
    void print24H()
    {
        cout << hours << ":" << minutes << endl;
    };

    void print12H()
    {
        cout << hours % 12 << ":" << minutes << endl;
    };

    void addMinute()
    {
        if (minutes + 1 == 60)
        {
            minutes = 0;
            hours += 1;
        }
        else
            minutes += 1;
    };
};

int main()
{
    return 0;
}