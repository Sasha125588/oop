#pragma once

#include "AccountException.hpp"

using namespace std;

class InvalidLoginException: public AccountException<string> {
    public:
    InvalidLoginException(const string& message, const string& InvalidLogin): AccountException(message, InvalidLogin) {}

};