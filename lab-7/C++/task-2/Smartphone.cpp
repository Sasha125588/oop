#include "Smartphone.hpp"

#include <iostream>
using namespace std;


void Smartphone::connectCharger(Charger* newCharger) {
    if(newCharger->getConnectorType() != this->requiredConnector) {
        cout << "Invalid connector type" << endl;
        return;
    }

    delete currentCharger;
    currentCharger = newCharger;
}

void Smartphone::disconnectCharger() {
    if(currentCharger != nullptr) {
        delete currentCharger;
        currentCharger = nullptr;
    }
}

void Smartphone::сhargerInfo() {
    if (currentCharger == nullptr) {
        cout << "Зарядний пристрій не підключений" << endl;
        return;
    }

    cout << "=== Інформація про зарядний пристрій ===" << endl;
    cout << "Тип роз'єму: ";
    
    if (currentCharger->getConnectorType() == USB_C) {
        cout << "USB Type-C";
    } else if (currentCharger->getConnectorType() == MICRO_USB) {
        cout << "Micro USB";
    }
    
    cout << endl;
    cout << "Потужність: " << currentCharger->getOutputPower() << " Вт" << endl;
}