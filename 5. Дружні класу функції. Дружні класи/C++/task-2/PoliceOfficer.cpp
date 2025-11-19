#include "PoliceOfficer.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

PoliceOfficer::PoliceOfficer() {
    officerName = "Unknown";
    badgeNumber = "Unknown";
    ticketCounter = 0;
}

PoliceOfficer::PoliceOfficer(const string& officerName, const string& badgeNumber) {
    this->officerName = officerName;
    this->badgeNumber = badgeNumber;
    ticketCounter = 0;
}

string PoliceOfficer::getOfficerName() const {
    return officerName;
}

void PoliceOfficer::setOfficerName(const string& officerName) {
    this->officerName = officerName;
}

string PoliceOfficer::getBadgeNumber() const {
    return badgeNumber;
}

void PoliceOfficer::setBadgeNumber(const string& badgeNumber) {
    this->badgeNumber = badgeNumber;
}

bool PoliceOfficer::isParkingTimeExpired(const ParkedCar& car, const ParkingMeter& meter) const {
    return car.getMinutesParked() > meter.getMinutesPurchased();
}

ParkingTicket* PoliceOfficer::issueParkingTicket(const ParkedCar& car, const ParkingMeter& meter) {
    if (isParkingTimeExpired(car, meter)) {
        ticketCounter++;
        return new ParkingTicket(car, meter, ticketCounter, officerName, badgeNumber);
    }
    return nullptr;
}

void PoliceOfficer::displayOfficerInfo() const {
    cout << "┌─────────────────────────────────────────────────┐" << endl;
    cout << "│              POLICE OFFICER INFO               │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    cout << "│ Officer Name:    " << setw(25) << left << officerName << "│" << endl;
    cout << "│ Badge Number:    " << setw(25) << left << badgeNumber << "│" << endl;
    cout << "│ Tickets Issued:  " << setw(25) << left << ticketCounter << "│" << endl;
    cout << "└─────────────────────────────────────────────────┘" << endl;
}

void PoliceOfficer::patrolCar(const ParkedCar& car, const ParkingMeter& meter) {
    cout << "\n🚔 OFFICER ON PATROL 🚔" << endl;
    cout << "Officer " << officerName << " (Badge #" << badgeNumber << ") is inspecting a vehicle..." << endl;
    
    cout << "\n📋 INSPECTION REPORT:" << endl;
    cout << "├─ Car Details:" << endl;
    cout << "│  Make: " << car.getMake() << " " << car.getModel() << endl;
    cout << "│  Color: " << car.getColor() << endl;
    cout << "│  License: " << car.getLicenseNumber() << endl;
    cout << "├─ Parking Status:" << endl;
    cout << "│  Minutes Parked: " << car.getMinutesParked() << endl;
    cout << "│  Minutes Paid: " << meter.getMinutesPurchased() << endl;
    
    if (isParkingTimeExpired(car, meter)) {
        int violationMinutes = car.getMinutesParked() - meter.getMinutesPurchased();
        cout << "│  ⚠️  VIOLATION: " << violationMinutes << " minutes over limit!" << endl;
        cout << "└─ Action: ISSUING PARKING TICKET" << endl;
        
        ParkingTicket* ticket = issueParkingTicket(car, meter);
        if (ticket != nullptr) {
            cout << "\n🎫 TICKET ISSUED! 🎫" << endl;
            ticket->displayTicket();
            delete ticket;
        }
    } else {
        cout << "│  ✅ No violation detected" << endl;
        cout << "└─ Action: No ticket issued" << endl;
    }
    
    cout << "\n" << string(50, '-') << endl;
}
