#include <string>
#include <cctype>
#include "PasswordFormatException.hpp"

using namespace std;

class Account
{
    private:
	string login, password;

    bool isValidPassword(const string& pass) const {
        if (pass.length() <= 7) return false;
        
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
            throw PasswordFormatException(password, 
                "Пароль повинен мати довжину більше 7 символів та містити хоч одну цифру, велику та малу букви, спецсимвол");
        }
        this->password = password;
    }

    const string& getLogin() const { return login; }

    const string& getPassword() const { return password; }

    void changePassword(const string& newPassword) {
        if (!isValidPassword(newPassword)) {
            throw PasswordFormatException(newPassword, 
                "Пароль повинен мати довжину більше 7 символів та містити хоч одну цифру, велику та малу букви, спецсимвол");
        }
        if (newPassword != password) {
            password = newPassword;
        }
    }

};
