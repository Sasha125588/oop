#pragma once

#include <stdexcept>
#include <string>

#include "BaseException.hpp"

using namespace std;

class InvalidNumberException : public BaseException<string>, public invalid_argument {
public:
  InvalidNumberException(const string &message, const string &invalidData)
      : BaseException(message, invalidData), invalid_argument(message) {}
};