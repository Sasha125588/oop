#include <iostream>
#include "Driver.hpp"
#include "Vehicle.hpp"
#include <string>
// #include <vector>
// #include <sstream>

// std::vector<std::string> split(const std::string& target, char c)
// {
// 	std::string temp;
// 	std::stringstream stringstream { target };
// 	std::vector<std::string> result;

// 	while (std::getline(stringstream, temp, c)) {
// 		result.push_back(temp);
// 	}

// 	return result;
// }

bool VehiclePointerComparator::operator()(const Vehicle* a, const Vehicle* b) const {
    return a->getRegistrationNumber() < b->getRegistrationNumber();
}

Driver::Driver()
{
    name = "";
    licenseNumber = 0;
}

Driver::Driver(const string &name, int licenseNum, const set<string> &certificateCategories) : name(name), licenseNumber(licenseNum), certificateCategories(certificateCategories) {}

void Driver::assignVehicle(Vehicle* vehicle)
{
    if (!certificateCategories.contains(vehicle->getCategory())) 
    {
        cout << "Category " << vehicle->getCategory() << " not found in the driver's certificate categories." << endl;
        return;
    }

    if (vehicle->getOwner() != nullptr)
    {
        cout << "Vehicle already has an owner" << endl;
        return;
    }

    if (vehicle->getOwner() == this)
    {
        cout << "Vehicle already assigned to this driver" << endl;
        return;
    }

    vehicle->owner = this;

    vehicles.insert(vehicle);
}

void Driver::releaseVehicle(Vehicle* vehicle)
{

    if (!vehicles.contains(vehicle))
    {
        cout << "Vehicle not found" << endl;
        return;
    }
    vehicle->owner = nullptr;
    vehicles.erase(vehicle);
}

void Driver::printVehicles() const
{
    cout << "=== Транспортные средства водителя " << name << " ===" << endl;
    cout << "Общее количество: " << vehicles.size() << endl << endl;
    
    if (vehicles.empty()) {
        cout << "Нет транспортных средств" << endl;
        return;
    }

    for (const auto &vehicle : vehicles)
    {
        cout << "🚗 Модель: " << vehicle->getModel() << endl;
        cout << "   Рег. номер: №" << vehicle->getRegistrationNumber() << endl;
        cout << "   Категория: " << vehicle->getCategory() << endl;
        cout << "   Статус страховки: " << vehicle->getInsuranceStatus() << endl;
        
        if (vehicle->hasInsurance()) {
            Insurance* ins = vehicle->getInsurance();
            cout << "   Страховая компания: " << ins->getCompanyName() << endl;
            cout << "   Номер полиса: " << ins->getPolicyNumber() << endl;
        }
        cout << endl;
    }
}