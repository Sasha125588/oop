#pragma once

#include "AccountException.hpp"

using namespace std;

class ExistLoginException: public AccountException<string> {
    public:
    ExistLoginException(const string& login, const string& message): AccountException(login, message) {}

};