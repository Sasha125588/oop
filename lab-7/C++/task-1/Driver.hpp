#pragma once

#include <string>
#include <set>

class Vehicle;
using namespace std;

struct VehiclePointerComparator {
    bool operator()(const Vehicle* a, const Vehicle* b) const;
};

class Driver {
    private:
    string name;
    int licenseNumber;
    set<string> certificateCategories;
    set<Vehicle*, VehiclePointerComparator> vehicles;

    public:
    Driver();
    Driver(const string& name, int licenseNum, const set<string>& certificateCategories);
    
    void assignVehicle(Vehicle* vehicle);
    void releaseVehicle(Vehicle* vehicle);
    int getVehicleCount() const { return vehicles.size(); }
    void printVehicles() const;
};