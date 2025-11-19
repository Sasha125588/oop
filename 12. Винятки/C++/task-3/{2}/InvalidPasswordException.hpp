#pragma once

#include "AccountException.hpp"

using namespace std;

class InvalidPasswordException: public AccountException<string> {
    public:
    InvalidPasswordException(const string& message, const string& InvalidPassword): AccountException(message, InvalidPassword) {}

};