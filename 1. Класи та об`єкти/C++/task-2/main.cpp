#include "./Clock.hpp"

void testClock();

int main()
{
    testClock();

    return 0;
}

void testClock()
{
    Clock clock;

    clock.addMinute();

    clock.print12H();
    clock.print24H();
}
