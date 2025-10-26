#pragma once

#include <string>
#include <unordered_set>

class Vehicle;
using namespace std;

// struct VehiclePointerComparator {
//     bool operator()(const Vehicle& a, const Vehicle& b) const;
// };

struct VehicleHash {
    size_t operator()(const Vehicle* v) const;
};

struct VehicleEqual {
    bool operator()(const Vehicle* a, const Vehicle* b) const;
};

class Driver {
    private:
    string name;
    int licenseNumber;
    unordered_set<string> certificateCategories;
    unordered_set<Vehicle*, VehicleHash, VehicleEqual> vehicles;

    public:
    Driver();
    Driver(const string& name, int licenseNum, const unordered_set<string>& certificateCategories);
    
    void assignVehicle(Vehicle* vehicle);
    void releaseVehicle(Vehicle* vehicle);
    int getVehicleCount() const { return vehicles.size(); }
    void printVehicles() const;
};