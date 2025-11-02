#include <stdexcept>
#include <string>
#include "BaseException.hpp"

using namespace std;

class WrongSpeedException : public BaseException<int>, public invalid_argument {
public:
  WrongSpeedException(const string &message, int invalidData)
      : BaseException(message, invalidData), invalid_argument(message) {}
};