#pragma once

#include <string>

using namespace std;

template<typename T>
class AccountException {
    private:
    string message;
    T invalidData;

    public:
    AccountException(T invalidData, const string &message): message(message), invalidData(invalidData) {}

    const string& getErrMsg() const { return message; }
    const T& getInvalidData() const { return invalidData; }

};