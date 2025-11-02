#pragma once

#include <stdexcept>
#include <string>

#include "BaseException.hpp"

using namespace std;

class WrongMaxSpeedException : public BaseException<int>, public invalid_argument {
public:

      WrongMaxSpeedException(const string &message, int invalidData)
  : BaseException(message, invalidData), invalid_argument(message) {}
};