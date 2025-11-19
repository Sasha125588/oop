#pragma once

#include "Driver.hpp"
#include "Insurance.hpp"
#include <string>

class Driver;
using namespace std;

class Vehicle {
    private:
    string model;
    int registrationNumber;
    string category;

    Driver* owner;
    Insurance* insurance;  

    public:
    Vehicle(const string& model, int regNumber, const string& category) 
        : model(model), registrationNumber(regNumber), owner(nullptr), category(category), insurance(nullptr) {}
    
    
    ~Vehicle() {
        if (insurance != nullptr) {
            delete insurance;
            insurance = nullptr;
        }
    }

    Vehicle(const Vehicle& other) 
        : model(other.model), registrationNumber(other.registrationNumber), 
          category(other.category), owner(other.owner), insurance(nullptr) {
        if (other.insurance != nullptr) {
            insurance = new Insurance(*other.insurance);
        }
    }

    Vehicle& operator=(const Vehicle& other) {
        if (this != &other) {
            model = other.model;
            registrationNumber = other.registrationNumber;
            category = other.category;
            owner = other.owner;
            
            if (insurance != nullptr) {
                delete insurance;
                insurance = nullptr;
            }
            if (other.insurance != nullptr) {
                insurance = new Insurance(*other.insurance);
            }
        }
        return *this;
    }

    string getModel() const { return model; }
    void setModel(const string& model) { this->model = model; }

    int getRegistrationNumber() const { return registrationNumber; }
    void setRegistrationNumber(int registrationNumber) { this->registrationNumber = registrationNumber; }

    string getCategory() const { return category; }
    void setCategory(const string& category) { this->category = category; }

    Driver* getOwner() const { return owner; }
    void setOwner(Driver* owner) { this->owner = owner; }

    
    void setInsurance(const string& company, const string& policy, const string& expDate, bool active = true) {
        if (insurance != nullptr) {
            delete insurance;
        }
        insurance = new Insurance(company, policy, expDate, active);
    }

    void removeInsurance() {
        if (insurance != nullptr) {
            delete insurance;
            insurance = nullptr;
        }
    }

    bool hasInsurance() const {
        return insurance != nullptr;
    }

    Insurance* getInsurance() const {
        return insurance;
    }

    string getInsuranceStatus() const {
        if (insurance == nullptr) {
            return "Немає страховки";
        }
        return insurance->getStatus();
    }

    bool operator==(const Vehicle& other) const {
        return registrationNumber == other.registrationNumber;
    }
    
    bool operator<(const Vehicle& other) const {
        return registrationNumber < other.registrationNumber;
    }

    friend class Driver;
};
