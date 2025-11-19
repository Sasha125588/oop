#pragma once

#include <stdexcept>
#include <string>


using namespace std;

class WrongMaxSpeedException : public invalid_argument {
public:

      WrongMaxSpeedException(const string &message)
  : invalid_argument(message) {}
};