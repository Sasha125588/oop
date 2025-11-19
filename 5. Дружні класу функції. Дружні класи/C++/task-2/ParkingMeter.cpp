#include "ParkingMeter.hpp"
#include <algorithm>


ParkingMeter::ParkingMeter() {
    minutesPurchased = 0;
}

ParkingMeter::ParkingMeter(int minutesPurchased) {
    this->minutesPurchased = minutesPurchased;
}

int ParkingMeter::getMinutesPurchased() const {
    return minutesPurchased;
}

void ParkingMeter::setMinutesPurchased(int minutesPurchased) {
    this->minutesPurchased = std::max(minutesPurchased, 0);
}
