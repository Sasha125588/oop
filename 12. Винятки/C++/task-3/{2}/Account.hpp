#include <string>
#include <cctype>
#include "PasswordFormatException.hpp"

using namespace std;

class Account
{
    private:

      static constexpr int MAX_ALLOWED_SPEED = 360;
      static constexpr size_t MIN_PASS_LENGTH = 8;

	string login, password;

    bool isValidPassword(const string& pass) const {
        if (pass.length() < MIN_PASS_LENGTH) return false;
        
        bool hasDigit = false;
        bool hasUpper = false;
        bool hasLower = false;
        bool hasSpecial = false;
        
        for (char c : pass) {
            if (isdigit(c)) hasDigit = true;
            else if (isupper(c)) hasUpper = true;
            else if (islower(c)) hasLower = true;
            else if (ispunct(c)) hasSpecial = true;
        }
        
        return hasDigit && hasUpper && hasLower && hasSpecial;
    }

    public:
    Account() = default;
    Account(const string& login, const string& password) : login(login) {
        if (!isValidPassword(password)) {
            throw PasswordFormatException(
                "Пароль повинен мати довжину більше 7 символів та містити хоч одну цифру, велику та малу букви, спецсимвол", password);
        }
        this->password = password;
    }

    const string& getLogin() const { return login; }

    const string& getPassword() const { return password; }

    void changePassword(const string& newPassword) {
        if (!isValidPassword(newPassword)) {
            throw PasswordFormatException( 
                "Пароль повинен мати довжину більше 7 символів та містити хоч одну цифру, велику та малу букви, спецсимвол", newPassword);
        }
        if (newPassword != password) {
            password = newPassword;
        }
    }
};
