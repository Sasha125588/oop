#include <stdexcept>
#include <string>

using namespace std;

class WrongTrianError: public invalid_argument {
    private:
    string message;

    public:
    WrongTrianError(const string& message): invalid_argument(message), message(message) {}

    const string& getErrMsg() const { return message; }
};