#include <stdexcept>
#include <string>

using namespace std;

class WrongSpeedException : public invalid_argument {
public:
  WrongSpeedException(const string &message)
      : invalid_argument(message) {}
};