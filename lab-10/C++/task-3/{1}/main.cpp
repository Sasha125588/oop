#include <iostream>
#include "Auto.hpp"

using namespace std;

void testMaxSpeedInConstructor();
void testSpeedExceedsMaxInConstructor();
void testInvalidNumberInConstructor();
void testSetMaxSpeed();
void testSetSpeed();
void testIncreaseSpeed();
void testSetNumber();
void testSuccessfulOperations();

int main()
{
    cout << "========================================" << endl;
    cout << "   ТЕСТУВАННЯ КЛАСУ AUTO" << endl;
    cout << "========================================" << endl;
    
    testMaxSpeedInConstructor();
    testSpeedExceedsMaxInConstructor();
    testInvalidNumberInConstructor();
    testSetMaxSpeed();
    testSetSpeed();
    testIncreaseSpeed();
    testSetNumber();
    testSuccessfulOperations();
    
    cout << "\n========================================" << endl;
    cout << "   ТЕСТУВАННЯ ЗАВЕРШЕНО" << endl;
    cout << "========================================" << endl;
    
    return 0;
}

// Тест 1: Перевірка WrongMaxSpeedException при створенні
void testMaxSpeedInConstructor() {
    cout << "\n=== Тест 1: Максимальна швидкість > 360 при створенні ===" << endl;
    try {
        Auto car("AB1234CD", 100, 400); // maxSpeed > 360
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const WrongMaxSpeedException& ex) {
        cout << "[УСПІШНО] Викинуто WrongMaxSpeedException: " << ex.getErrMsg() << endl;
    } catch (...) {
        cout << "Помилка: викинуто неочікуваний тип винятку!" << endl;
    }
}

// Тест 2: Перевірка WrongSpeedException при створенні
void testSpeedExceedsMaxInConstructor() {
    cout << "\n=== Тест 2: Швидкість > максимальної при створенні ===" << endl;
    try {
        Auto car("AB1234CD", 250, 200); // speed > maxSpeed
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const WrongSpeedException& ex) {
        cout << "[УСПІШНО] Викинуто WrongSpeedException: " << ex.getErrMsg() << endl;
    } catch (...) {
        cout << "Помилка: викинуто неочікуваний тип винятку!" << endl;
    }
}

// Тест 3: Перевірка InvalidNumberException при створенні
void testInvalidNumberInConstructor() {
    cout << "\n=== Тест 3: Невалідний номер при створенні ===" << endl;
    
    // Тест 3.1: Неправильна довжина
    try {
        Auto car("AB123CD", 100, 200); // 7 символів замість 8
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const InvalidNumberException& ex) {
        cout << "[УСПІШНО] Викинуто InvalidNumberException (довжина): " << ex.getErrMsg() << endl;
    }
    
    // Тест 3.2: Малі літери замість великих
    try {
        Auto car("ab1234CD", 100, 200);
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const InvalidNumberException& ex) {
        cout << "[УСПІШНО] Викинуто InvalidNumberException (малі літери): " << ex.getErrMsg() << endl;
    }
    
    // Тест 3.3: Літери замість цифр
    try {
        Auto car("ABCD34CD", 100, 200);
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const InvalidNumberException& ex) {
        cout << "[УСПІШНО] Викинуто InvalidNumberException (літери в номері): " << ex.getErrMsg() << endl;
    }
    
    // Тест 3.4: Цифри замість літер
    try {
        Auto car("AB123456", 100, 200);
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const InvalidNumberException& ex) {
        cout << "[УСПІШНО] Викинуто InvalidNumberException (цифри в кінці): " << ex.getErrMsg() << endl;
    }
}

// Тест 4: Перевірка setMaxSpeed()
void testSetMaxSpeed() {
    cout << "\n=== Тест 4: Метод setMaxSpeed() ===" << endl;
    
    try {
        Auto car("AB1234CD", 100, 200);
        cout << "Початкова максимальна швидкість: " << car.getMaxSpeed() << endl;
        
        // Спроба встановити maxSpeed > 360
        car.setMaxSpeed(400);
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const WrongMaxSpeedException& ex) {
        cout << "[УСПІШНО] Викинуто WrongMaxSpeedException: " << ex.getErrMsg() << endl;
    }
    
    try {
        Auto car("AB1234CD", 150, 200);
        // Спроба встановити maxSpeed менше поточної швидкості
        car.setMaxSpeed(100); // поточна швидкість 150 > нова maxSpeed 100
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const WrongSpeedException& ex) {
        cout << "[УСПІШНО] Викинуто WrongSpeedException: " << ex.getErrMsg() << endl;
    }
}

// Тест 5: Перевірка setSpeed()
void testSetSpeed() {
    cout << "\n=== Тест 5: Метод setSpeed() ===" << endl;
    
    try {
        Auto car("AB1234CD", 100, 200);
        cout << "Поточна швидкість: " << car.getSpeed() << endl;
        
        // Спроба встановити швидкість > максимальної
        car.setSpeed(250);
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const WrongSpeedException& ex) {
        cout << "[УСПІШНО] Викинуто WrongSpeedException: " << ex.getErrMsg() << endl;
    }
}

// Тест 6: Перевірка increaseSpeed()
void testIncreaseSpeed() {
    cout << "\n=== Тест 6: Метод increaseSpeed() ===" << endl;
    
    try {
        Auto car("AB1234CD", 195, 200);
        cout << "Поточна швидкість: " << car.getSpeed() << " км/год" << endl;
        cout << "Максимальна швидкість: " << car.getMaxSpeed() << " км/год" << endl;
        
        // Спроба збільшити швидкість на 10 (195 + 10 = 205 > 200)
        car.increaseSpeed(10);
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const WrongSpeedException& ex) {
        cout << "[УСПІШНО] Викинуто WrongSpeedException: " << ex.getErrMsg() << endl;
    }
}

// Тест 7: Перевірка setNumber()
void testSetNumber() {
    cout << "\n=== Тест 7: Метод setNumber() ===" << endl;
    
    try {
        Auto car("AB1234CD", 100, 200);
        cout << "Поточний номер: " << car.getNumber() << endl;
        
        // Спроба встановити невалідний номер
        car.setNumber("123456AB");
        cout << "Помилка: виняток не було викинуто!" << endl;
    } catch (const InvalidNumberException& ex) {
        cout << "[УСПІШНО] Викинуто InvalidNumberException: " << ex.getErrMsg() << endl;
    }
}

// Тест 8: Успішне створення та робота
void testSuccessfulOperations() {
    cout << "\n=== Тест 8: Успішні операції ===" << endl;
    
    try {
        Auto car("KA1234BX", 50, 220);
        cout << "Автомобіль створено успішно!" << endl;
        cout << "Номер: " << car.getNumber() << endl;
        cout << "Швидкість: " << car.getSpeed() << " км/год" << endl;
        cout << "Максимальна швидкість: " << car.getMaxSpeed() << " км/год" << endl;
        
        // Збільшення швидкості
        car.increaseSpeed(20);
        cout << "Після збільшення: " << car.getSpeed() << " км/год" << endl;
        
        // Зменшення швидкості
        car.decreaseSpeed(10);
        cout << "Після зменшення: " << car.getSpeed() << " км/год" << endl;
        
        // Зміна номера
        car.setNumber("XX9999YY");
        cout << "Новий номер: " << car.getNumber() << endl;
        
        cout << "[УСПІШНО] Всі операції виконано без помилок" << endl;
        
    } catch (...) {
        cout << "Помилка: несподіваний виняток!" << endl;
    }
}