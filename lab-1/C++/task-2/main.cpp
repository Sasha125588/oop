#include "./Clock.hpp"

void testClock();

int main()
{
    return 0;
}

void testClock() {
    Clock clock;

    clock.print12H();
    clock.print24H();
}
