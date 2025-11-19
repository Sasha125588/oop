#pragma once

#include <string>

using namespace std;

class Insurance {
private:
    string companyName;     
    string policyNumber;    
    string expirationDate;  
    bool isActive;          

public:
    Insurance(const string& company, const string& policy, const string& expDate, bool active = true)
        : companyName(company), policyNumber(policy), expirationDate(expDate), isActive(active) {}

    string getCompanyName() const { return companyName; }
    string getPolicyNumber() const { return policyNumber; }
    string getExpirationDate() const { return expirationDate; }
    bool getIsActive() const { return isActive; }

    void setCompanyName(const string& company) { companyName = company; }
    void setPolicyNumber(const string& policy) { policyNumber = policy; }
    void setExpirationDate(const string& expDate) { expirationDate = expDate; }
    void setIsActive(bool active) { isActive = active; }

    string getStatus() const {
        if (isActive) {
            return "Активна (до " + expirationDate + ")";
        }
        return "Неактивна";
    }
};

