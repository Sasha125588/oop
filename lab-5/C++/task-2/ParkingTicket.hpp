#pragma once
#include "ParkedCar.hpp"
#include "ParkingMeter.hpp"
#include <string>

using namespace std;

class ParkingTicket {
private:
    ParkedCar* parkedCar;
    ParkingMeter* parkingMeter;
    int ticketNumber;
    
    string officerName;
    string badgeNumber;
    
    int calculateFine() const;

public:
    ParkingTicket();
    
    ParkingTicket(const ParkedCar& car, const ParkingMeter& meter, 
                  int ticketNumber, const string& officerName, 
                  const string& badgeNumber);
    
    ~ParkingTicket();
    
    ParkedCar& getParkedCar() const;    
    ParkingMeter& getParkingMeter() const;
    int getTicketNumber() const;
    string getOfficerName() const;
    string getBadgeNumber() const;
    int getFineAmount() const;
    
    void setParkedCar(const ParkedCar& car);
    void setParkingMeter(const ParkingMeter& meter);
    void setTicketNumber(int ticketNumber);
    void setOfficerName(const string& officerName);
    void setBadgeNumber(const string& badgeNumber);
    
    void displayTicket() const;
    void displayCarInfo() const;
    void displayFineInfo() const;
    void displayOfficerInfo() const;
};