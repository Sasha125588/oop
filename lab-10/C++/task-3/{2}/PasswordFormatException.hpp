#pragma once

#include "AccountException.hpp"

using namespace std;

class PasswordFormatException: public AccountException<string> {
    public:
    PasswordFormatException(const string& message, const string& InvalidPassword): AccountException(message, InvalidPassword) {}

};