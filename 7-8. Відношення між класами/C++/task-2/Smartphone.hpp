#pragma once

#include <string>
#include "Charger.hpp"

using namespace std;

class Smartphone {
    private: 
    string brand;
	string model;
	int batteryCapacity;
	ConnectorType requiredConnector;

    Charger* currentCharger;

    public:
    Smartphone(const string& brand, const string& model, int batteryCapacity, ConnectorType requiredConnector)
        : brand(brand), model(model), batteryCapacity(batteryCapacity), requiredConnector(requiredConnector), currentCharger(nullptr) {}
    
    ~Smartphone() {
        if (currentCharger != nullptr) {
            delete currentCharger;
        }
    }

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getBatteryCapacity() const { return batteryCapacity; }

    void connectCharger(Charger* newCharger);
    void disconnectCharger();
    void сhargerInfo();
};