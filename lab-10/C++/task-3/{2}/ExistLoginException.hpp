#pragma once

#include "AccountException.hpp"

using namespace std;

class ExistLoginException: public AccountException<string> {
    public:
    ExistLoginException(const string& message, const string& invalidLogin): AccountException(message, invalidLogin) {}

};