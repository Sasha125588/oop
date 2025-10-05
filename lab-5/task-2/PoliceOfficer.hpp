#pragma once
#include "ParkedCar.hpp"
#include "ParkingMeter.hpp"
#include "ParkingTicket.hpp"
#include <string>

using namespace std;

class PoliceOfficer {
private:
    string officerName;
    string badgeNumber;
    int ticketCounter;

public:
    PoliceOfficer();
    PoliceOfficer(const string& officerName, const string& badgeNumber);
    
    string getOfficerName() const;
    void setOfficerName(const string& officerName);
    
    string getBadgeNumber() const;
    void setBadgeNumber(const string& badgeNumber);
    
    bool isParkingTimeExpired(const ParkedCar& car, const ParkingMeter& meter) const;
    
    ParkingTicket* issueParkingTicket(const ParkedCar& car, const ParkingMeter& meter);
    
    void displayOfficerInfo() const;
    
    void patrolCar(const ParkedCar& car, const ParkingMeter& meter);
};
