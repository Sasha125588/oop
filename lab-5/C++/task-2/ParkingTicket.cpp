#include "ParkingTicket.hpp"
#include "ParkedCar.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

ParkingTicket::ParkingTicket() {
    parkedCar = new ParkedCar();
    parkingMeter = new ParkingMeter();
    ticketNumber = 0;
    officerName = "Unknown";
    badgeNumber = "Unknown";
}

ParkingTicket::ParkingTicket(const ParkedCar* car, const ParkingMeter* meter, 
                             int ticketNumber, const string& officerName, 
                             const string& badgeNumber) {
    this->parkedCar = new ParkedCar(*car);
    this->parkingMeter = new ParkingMeter(*meter);
    this->ticketNumber = ticketNumber;
    this->officerName = officerName;
    this->badgeNumber = badgeNumber;
}

ParkingTicket::~ParkingTicket() {
    delete parkedCar;
    delete parkingMeter;
}

ParkedCar& ParkingTicket::getParkedCar() const {
    return *parkedCar;
}

ParkingMeter& ParkingTicket::getParkingMeter() const {
    return *parkingMeter;
}

int ParkingTicket::getTicketNumber() const {
    return ticketNumber;
}

string ParkingTicket::getOfficerName() const {
    return officerName;
}

string ParkingTicket::getBadgeNumber() const {
    return badgeNumber;
}

int ParkingTicket::getFineAmount() const {
    return calculateFine();
}

void ParkingTicket::setParkedCar(const ParkedCar* car) {
    parkedCar = new ParkedCar(*car);
}

void ParkingTicket::setParkingMeter(const ParkingMeter* meter) {
    parkingMeter = new ParkingMeter(*meter);
}

void ParkingTicket::setTicketNumber(int ticketNumber) {
    this->ticketNumber = ticketNumber;
}

void ParkingTicket::setOfficerName(const string& officerName) {
    this->officerName = officerName;
}

void ParkingTicket::setBadgeNumber(const string& badgeNumber) {
    this->badgeNumber = badgeNumber;
}

int ParkingTicket::calculateFine() const {
    int minutesParked = parkedCar->getMinutesParked();
    int minutesPurchased = parkingMeter->getMinutesPurchased();
    
    if (minutesParked <= minutesPurchased) {
        return 0;
    }
    
    int violationMinutes = minutesParked - minutesPurchased;
    
    double violationHours = ceil(violationMinutes / 60.0); // 140 хв |=> ceil(140 / 60.0) = 3 години(округляємо вверх)
    
    int fine = 0;
    
    if (violationHours > 0) {
        fine += 25;
        
        if (violationHours > 1) {
            fine += (violationHours - 1) * 10;
        }
    }
    
    return fine;
}

void ParkingTicket::displayCarInfo() const {
    cout << "┌─────────────────────────────────────────────────┐" << endl;
    cout << "│              VIOLATOR CAR INFO                  │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    cout << "│ Make:            " << setw(25) << left << parkedCar->getMake() << "│" << endl;
    cout << "│ Model:           " << setw(25) << left << parkedCar->getModel() << "│" << endl;
    cout << "│ Color:           " << setw(25) << left << parkedCar->getColor() << "│" << endl;
    cout << "│ License Number:  " << setw(25) << left << parkedCar->getLicenseNumber() << "│" << endl;
    cout << "│ Minutes Parked:  " << setw(25) << left << parkedCar->getMinutesParked() << "│" << endl;
    cout << "│ Minutes Paid:    " << setw(25) << left << parkingMeter->getMinutesPurchased() << "│" << endl;
    cout << "└─────────────────────────────────────────────────┘" << endl;
}

void ParkingTicket::displayFineInfo() const {
    int fine = calculateFine();
    int violationMinutes = parkedCar->getMinutesParked() - parkingMeter->getMinutesPurchased();
    int violationHours = ceil(violationMinutes / 60);
    
    cout << "┌─────────────────────────────────────────────────┐" << endl;
    cout << "│                FINE INFORMATION                 │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    
    if (fine == 0) {
        cout << "│ Status:          NO VIOLATION                │" << endl;
        cout << "│ Fine Amount:     $0                       │" << endl;
    } else {
        cout << "│ Violation Time:  " << setw(4) << left << violationMinutes 
             << " minutes (" << fixed << setprecision(1) << violationHours 
             << " hours)     │" << endl;
        cout << "│ Fine Amount:     $" << setw(8) << left << fixed << setprecision(2) << fine << "           │" << endl;
        cout << "│                                                 │" << endl;
        cout << "│ Fine Breakdown:                               │" << endl;
        cout << "│ - First hour:    $25                       │" << endl;
        if (violationHours > 1) {
            cout << "│ - Additional:    $" << setw(8) << left << fixed << setprecision(2) 
                 << (violationHours - 1) * 10 << " (" << violationHours - 1 << " hrs)    │" << endl;
        }
    }
    
    cout << "└─────────────────────────────────────────────────┘" << endl;
}

void ParkingTicket::displayOfficerInfo() const {
    cout << "┌─────────────────────────────────────────────────┐" << endl;
    cout << "│            ISSUING OFFICER INFO                 │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    cout << "│ Officer Name:    " << setw(25) << left << officerName << "│" << endl;
    cout << "│ Badge Number:    " << setw(25) << left << badgeNumber << "│" << endl;
    cout << "└─────────────────────────────────────────────────┘" << endl;
}

void ParkingTicket::displayTicket() const {
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    PARKING VIOLATION TICKET                  ║" << endl;
    cout << "║                      Ticket #" << setw(6) << left << ticketNumber << "                        ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════════╝" << endl;
    
    displayCarInfo();
    cout << "\n";
    displayFineInfo();
    cout << "\n";
    displayOfficerInfo();
    
    cout << "\n╔═══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║  Please pay the fine within 30 days to avoid additional fees  ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════════╝" << endl;
}
