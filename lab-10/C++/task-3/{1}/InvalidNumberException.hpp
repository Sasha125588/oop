#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class InvalidNumberException : public invalid_argument {
public:
  InvalidNumberException(const string &message)
      : invalid_argument(message) {}
};