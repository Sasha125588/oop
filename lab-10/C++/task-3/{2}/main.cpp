#include <iostream>
#include "SocialNetwork.hpp"

using namespace std;

void testPasswordFormat();
void testExistingLogin();
void testInvalidLogin();
void testInvalidPassword();
void testSuccessfulOperations();

int main()
{
    cout << "========================================" << endl;
    cout << "   ТЕСТУВАННЯ СОЦІАЛЬНОЇ МЕРЕЖІ" << endl;
    cout << "========================================" << endl;
    
    testPasswordFormat();
    testExistingLogin();
    testInvalidLogin();
    testInvalidPassword();
    testSuccessfulOperations();
    
    cout << "\n========================================" << endl;
    cout << "   ТЕСТУВАННЯ ЗАВЕРШЕНО" << endl;
    cout << "========================================" << endl;
    
    return 0;
}

// Тест 1: Перевірка формату пароля
void testPasswordFormat() {
    cout << "\n=== Тест 1: Невірний формат пароля ===" << endl;
    SocialNetwork network;
    
    // Тест 1.1: Занадто короткий пароль
    try {
        network.signup("user1", "Pass1!");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const PasswordFormatException& ex) {
        cout << "[УСПІШНО] Короткий пароль: " << ex.getErrMsg() << endl;
    }
    
    // Тест 1.2: Немає цифри
    try {
        network.signup("user2", "Password!");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const PasswordFormatException& ex) {
        cout << "[УСПІШНО] Без цифри: " << ex.getErrMsg() << endl;
    }
    
    // Тест 1.3: Немає великої літери
    try {
        network.signup("user3", "password1!");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const PasswordFormatException& ex) {
        cout << "[УСПІШНО] Без великої літери: " << ex.getErrMsg() << endl;
    }
    
    // Тест 1.4: Немає малої літери
    try {
        network.signup("user4", "PASSWORD1!");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const PasswordFormatException& ex) {
        cout << "[УСПІШНО] Без малої літери: " << ex.getErrMsg() << endl;
    }
    
    // Тест 1.5: Немає спецсимволу
    try {
        network.signup("user5", "Password1");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const PasswordFormatException& ex) {
        cout << "[УСПІШНО] Без спецсимволу: " << ex.getErrMsg() << endl;
    }
}

// Тест 2: Перевірка існуючого логіну
void testExistingLogin() {
    cout << "\n=== Тест 2: Реєстрація з існуючим логіном ===" << endl;
    SocialNetwork network;
    
    try {
        // Реєстрація першого користувача
        network.signup("alex123", "MyPass123!");
        cout << "Користувач 'alex123' зареєстрований" << endl;
        
        // Спроба зареєструвати ще раз з тим самим логіном
        network.signup("alex123", "DifferentPass456@");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const ExistLoginException& ex) {
        cout << "[УСПІШНО] ExistLoginException: " << ex.getErrMsg() << endl;
    } catch (...) {
        cout << "Помилка: неочікуваний виняток!" << endl;
    }
}

// Тест 3: Перевірка неіснуючого логіну при вході
void testInvalidLogin() {
    cout << "\n=== Тест 3: Вхід з неіснуючим логіном ===" << endl;
    SocialNetwork network;
    
    try {
        network.signup("john_doe", "SecurePass1@");
        cout << "Користувач 'john_doe' зареєстрований" << endl;
        
        // Спроба ввійти з неіснуючим логіном
        network.login("jane_doe", "SomePass1!");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const InvalidLoginException& ex) {
        cout << "[УСПІШНО] InvalidLoginException: " << ex.getErrMsg() << endl;
    } catch (...) {
        cout << "Помилка: неочікуваний виняток!" << endl;
    }
}

// Тест 4: Перевірка невірного пароля
void testInvalidPassword() {
    cout << "\n=== Тест 4: Вхід з невірним паролем ===" << endl;
    SocialNetwork network;
    
    try {
        network.signup("maria_k", "MyPassword123#");
        cout << "Користувач 'maria_k' зареєстрований" << endl;
        
        // Спроба ввійти з невірним паролем
        network.login("maria_k", "WrongPassword456!");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const InvalidPasswordException& ex) {
        cout << "[УСПІШНО] InvalidPasswordException: " << ex.getErrMsg() << endl;
    } catch (...) {
        cout << "Помилка: неочікуваний виняток!" << endl;
    }
}

// Тест 5: Успішні операції
void testSuccessfulOperations() {
    cout << "\n=== Тест 5: Успішна реєстрація та вхід ===" << endl;
    SocialNetwork network;
    
    try {
        // Реєстрація декількох користувачів
        network.signup("alice2024", "AlicePass123!");
        cout << "✓ Користувач 'alice2024' успішно зареєстрований" << endl;
        
        network.signup("bob_smith", "BobSecure456@");
        cout << "✓ Користувач 'bob_smith' успішно зареєстрований" << endl;
        
        network.signup("charlie99", "Charlie789#Strong");
        cout << "✓ Користувач 'charlie99' успішно зареєстрований" << endl;
        
        cout << "Всього користувачів: " << network.getUsersCount() << endl;
        
        // Успішні входи
        network.login("alice2024", "AlicePass123!");
        cout << "✓ Користувач 'alice2024' успішно ввійшов" << endl;
        
        network.login("bob_smith", "BobSecure456@");
        cout << "✓ Користувач 'bob_smith' успішно ввійшов" << endl;
        
        network.login("charlie99", "Charlie789#Strong");
        cout << "✓ Користувач 'charlie99' успішно ввійшов" << endl;
        
        cout << "[УСПІШНО] Всі операції виконано без помилок" << endl;
        
    } catch (const AccountException<string>& ex) {
        cout << "Помилка: " << ex.getErrMsg() << endl;
    } catch (...) {
        cout << "Помилка: неочікуваний виняток!" << endl;
    }
}
