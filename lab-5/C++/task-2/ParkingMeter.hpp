#pragma once

class ParkingMeter {
private:
    int minutesPurchased;

public:
    ParkingMeter();
    ParkingMeter(int minutesPurchased);

    int getMinutesPurchased() const;
    void setMinutesPurchased(int minutesPurchased);
};