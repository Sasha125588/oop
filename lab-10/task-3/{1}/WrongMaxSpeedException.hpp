#include <stdexcept>
#include <string>

using namespace std;

class WrongMaxSpeedException : public invalid_argument {
private:
  string message;
  int invalidData;

public:
  WrongMaxSpeedException(int invalidData, const string &message)
      : invalid_argument(message), message(message),
        invalidData(invalidData) {}

  const string& getErrMsg() const { return message; }
  int getInvalidData() const { return invalidData; }
};