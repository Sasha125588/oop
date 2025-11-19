#include <stdexcept>
#include <string>

using namespace std;

class WrongSideError: public invalid_argument {
    public:
      WrongSideError(const string& message): invalid_argument(message) {}

};