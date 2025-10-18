#pragma once

#include "AccountException.hpp"

using namespace std;

class InvalidPasswordException: public AccountException<string> {
    public:
    InvalidPasswordException(const string& password, const string& message): AccountException(password, message) {}

};