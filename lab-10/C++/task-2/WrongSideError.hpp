#include <stdexcept>
#include <string>

using namespace std;

class WrongSideError: public invalid_argument {
    private:
      string message;

    public:
      WrongSideError(const string& message): invalid_argument(message), message(message) {}

      const string& getErrMsg() const { return message; }
};