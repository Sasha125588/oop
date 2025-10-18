#pragma once

#include "AccountException.hpp"

using namespace std;

class InvalidLoginException: public AccountException<string> {
    public:
    InvalidLoginException(const string& login, const string& message): AccountException(login, message) {}

};