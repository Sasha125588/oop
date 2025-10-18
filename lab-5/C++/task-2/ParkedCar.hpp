#pragma once
#include <string>

using namespace std;

class ParkedCar {
private:
    string make;        
    string model;       
    string color;       
    string licenseNumber; 
    int minutesParked;       

public:
    ParkedCar();
    
    ParkedCar(const string& make, const string& model, 
              const string& color, const string& licenseNumber, 
              int minutesParked);
    
    string getMake() const;
    void setMake(const string& make);

    string getModel() const;
    void setModel(const string& model);

    string getColor() const;
    void setColor(const string& color);

    string getLicenseNumber() const;
    void setLicenseNumber(const string& licenseNumber);

    int getMinutesParked() const;
    void setMinutesParked(int minutesParked);
        
    void displayInfo() const;
};