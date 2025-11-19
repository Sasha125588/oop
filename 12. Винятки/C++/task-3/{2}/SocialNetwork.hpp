#include <string>
#include <vector>

#include "Account.hpp"
#include "ExistLoginException.hpp"
#include "InvalidLoginException.hpp"
#include "InvalidPasswordException.hpp"

using namespace std;

class SocialNetwork {
private:
  vector<Account*> accounts;

public:
  void signup(const string &login, const string &password) {
    for (const auto &user : accounts) {
      if (user->getLogin() == login) {
        throw ExistLoginException("Логін '" + login + "' вже існує в системі", login);
      }
    }
    
    Account* user = new Account(login, password);
    accounts.push_back(user);
  }

  void login(const string &login, const string &password) {
    bool found = false;
    
    for (const auto &user : accounts) {
      if (user->getLogin() == login) {
        found = true;
        if (user->getPassword() != password) {
          throw InvalidPasswordException("Невірний пароль для логіну '" + login + "'", password);
        }
        return;
      }
    }
    
    if (!found) {
      throw InvalidLoginException("Логін '" + login + "' не знайдено в системі", login);
    }
  }

  int getUsersCount() const {
    return accounts.size();
  }
};
