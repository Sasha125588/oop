#include "ParkedCar.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

ParkedCar::ParkedCar() {
    make = "Unknown";
    model = "Unknown";
    color = "Unknown";
    licenseNumber = "UNKNOWN";
    minutesParked = 0;
}

ParkedCar::ParkedCar(const string& make, const string& model, 
                     const string& color, const string& licenseNumber, 
                     int minutesParked) {
    this->make = make;
    this->model = model;
    this->color = color;
    this->licenseNumber = licenseNumber;
    this->minutesParked = minutesParked;
}

string ParkedCar::getMake() const {
    return make;
}

void ParkedCar::setMake(const string& make) {
    this->make = make;
}

string ParkedCar::getModel() const {
    return model;
}

void ParkedCar::setModel(const string& model) {
    this->model = model;
}

string ParkedCar::getColor() const {
    return color;
}

void ParkedCar::setColor(const string& color) {
    this->color = color;
}

string ParkedCar::getLicenseNumber() const {
    return licenseNumber;
}

void ParkedCar::setLicenseNumber(const string& licenseNumber) {
    this->licenseNumber = licenseNumber;
}

int ParkedCar::getMinutesParked() const {
    return minutesParked;
}

void ParkedCar::setMinutesParked(int minutesParked) {
    this->minutesParked = minutesParked;
}

void ParkedCar::displayInfo() const {
    cout << "┌─────────────────────────────────────────────────┐" << endl;
    cout << "│                  PARKED CAR                     │" << endl;
    cout << "├─────────────────────────────────────────────────┤" << endl;
    cout << "│ Make:            " << setw(25) << left << make << "│" << endl;
    cout << "│ Model:           " << setw(25) << left << model << "│" << endl;
    cout << "│ Color:           " << setw(25) << left << color << "│" << endl;
    cout << "│ License:         " << setw(25) << left << licenseNumber << "│" << endl;
    cout << "│ Minutes Parked:  " << setw(25) << left << minutesParked << "│" << endl;
    cout << "└─────────────────────────────────────────────────┘" << endl;
}
