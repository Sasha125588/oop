#include <cstddef>
#include <iostream>
#include "Driver.hpp"
#include "Vehicle.hpp"
#include <string>
#include <unordered_set>

using namespace std;

size_t VehicleHash::operator()(const Vehicle* v) const {
    return hash<int>()(v->getRegistrationNumber());
}

bool VehicleEqual::operator()(const Vehicle* a, const Vehicle* b) const {
    return a->getRegistrationNumber() == b->getRegistrationNumber();
}

Driver::Driver()
{
    name = "";
    licenseNumber = 0;
}

Driver::Driver(const string &name, int licenseNum, const unordered_set<string> &certificateCategories)
    : name(name), licenseNumber(licenseNum), certificateCategories(certificateCategories) {}

void Driver::assignVehicle(Vehicle* vehicle)
{
    if (!certificateCategories.contains(vehicle->getCategory())) 
    {
        cout << "❌ Категорія " << vehicle->getCategory()
             << " відсутня у посвідченні водія." << endl;
        return;
    }

    if (vehicle->getOwner() != nullptr)
    {
        cout << "❌ Транспорт вже має власника." << endl;
        return;
    }

    if (vehicle->getOwner() == this)
    {
        cout << "⚠️ Транспорт вже закріплений за цим водієм." << endl;
        return;
    }

    vehicle->owner = this;
    vehicles.insert(vehicle);

    cout << "✅ Транспорт \"" << vehicle->getModel() << "\" успішно призначено водію " << name << "." << endl;
}

void Driver::releaseVehicle(Vehicle* vehicle)
{
    if (!vehicles.contains(vehicle))
    {
        cout << "❌ Транспорт не знайдено серед призначених." << endl;
        return;
    }

    vehicle->owner = nullptr;
    vehicles.erase(vehicle);

    cout << "✅ Транспорт \"" << vehicle->getModel() << "\" успішно відкріплено від водія " << name << "." << endl;
}

void Driver::printVehicles() const
{
    cout << "=====================================" << endl;
    cout << "🚘 Транспортні засоби водія: " << name << endl;
    cout << "Загальна кількість: " << vehicles.size() << endl << endl;
    
    if (vehicles.empty()) {
        cout << "ℹ️ Немає закріплених транспортних засобів." << endl;
        return;
    }

    for (const auto &vehicle : vehicles)
    {
        cout << "🚗 Модель: " << vehicle->getModel() << endl;
        cout << "   Реєстраційний номер: №" << vehicle->getRegistrationNumber() << endl;
        cout << "   Категорія: " << vehicle->getCategory() << endl;
        cout << "   Статус страховки: " << vehicle->getInsuranceStatus() << endl;
        
        if (vehicle->hasInsurance()) {
            Insurance* ins = vehicle->getInsurance();
            cout << "   Страхова компанія: " << ins->getCompanyName() << endl;
            cout << "   Номер полісу: " << ins->getPolicyNumber() << endl;
        }
        cout << endl;
    }
}
