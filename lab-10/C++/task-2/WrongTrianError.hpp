#include <stdexcept>
#include <string>

using namespace std;

class WrongTrianError: public invalid_argument {

    public:
    WrongTrianError(const string& message): invalid_argument(message) {}
};