#include <stdexcept>
#include <string>

using namespace std;

class InvalidNumberException : public invalid_argument {
private:
  string message;
  string invalidData;

public:
  InvalidNumberException(const string &invalidData, const string &message)
      : invalid_argument(message), message(message),
      invalidData(invalidData) {}

  const string &getErrMsg() const { return message; }
  const string &getInvalidData() const { return invalidData; }
};