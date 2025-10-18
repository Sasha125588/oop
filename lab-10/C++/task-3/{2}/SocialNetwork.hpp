#include <string>
#include <vector>

#include "Account.hpp"
#include "ExistLoginException.hpp"
#include "InvalidLoginException.hpp"
#include "InvalidPasswordException.hpp"

using namespace std;

class SocialNetwork {
private:
  vector<Account> accounts;

public:
  void signup(const string &login, const string &password) {
    for (const auto &u : accounts) {
      if (u.getLogin() == login) {
        throw ExistLoginException(login, "Логін '" + login + "' вже існує в системі");
      }
    }
    
    Account user(login, password);
    accounts.push_back(user);
  }

  void login(const string &login, const string &password) {
    bool found = false;
    
    for (const auto &u : accounts) {
      if (u.getLogin() == login) {
        found = true;
        if (u.getPassword() != password) {
          throw InvalidPasswordException(password, "Невірний пароль для логіну '" + login + "'");
        }
        return;
      }
    }
    
    if (!found) {
      throw InvalidLoginException(login, "Логін '" + login + "' не знайдено в системі");
    }
  }

  int getUserCount() const {
    return accounts.size();
  }
};
