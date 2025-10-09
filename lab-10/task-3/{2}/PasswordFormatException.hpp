#pragma once

#include "AccountException.hpp"

using namespace std;

class PasswordFormatException: public AccountException<string> {
    public:
    PasswordFormatException(const string& password, const string& message): AccountException(password, message) {}

};