#include <stdexcept>
#include <string>

using namespace std;

class WrongSpeedException : public invalid_argument {
private:
  string message;
  int invalidData;

public:
  WrongSpeedException(int invalidData, const string &message)
      : invalid_argument(message), message(message),
      invalidData(invalidData) {}

  const string& getErrMsg() const { return message; }
  int getInvalidData() const { return invalidData; }
};