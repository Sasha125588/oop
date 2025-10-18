#include <iostream>
#include "Device.hpp"
#include "Smartphone.hpp"
#include "Tablet.hpp"
#include "Speakers.hpp"
#include "Smartwatch.hpp"

using namespace std;

void separator(const string& title);
void testBasicFunctionality();
void testObjectSlicing();
void testPointers();
void testReferences();
void processDevice(Device device);
void processDeviceByPointer(Device* device);
void processDeviceByReference(Device& device);
void testPolymorphicArray();
void testFunctionParameters();


int main() {
    cout << "\n";
    cout << "████████████████████████████████████████████████████████████" << endl;
    cout << "█                                                          █" << endl;
    cout << "█    ЛАБОРАТОРНА РОБОТА 8: ТЕСТУВАННЯ УСПАДКУВАННЯ        █" << endl;
    cout << "█                                                          █" << endl;
    cout << "████████████████████████████████████████████████████████████" << endl;
    
    // Виконуємо всі тести
    testBasicFunctionality();
    testObjectSlicing();
    testPointers();
    testReferences();
    testFunctionParameters();
    testPolymorphicArray();
    
    separator("ПІДСУМОК");
    cout << "ПРИ ВІДКРИТОМУ УСПАДКУВАННІ:" << endl;
    cout << "\n1. ПРИСВОЄННЯ ОБ'ЄКТІВ (Device d = smartphone):" << endl;
    cout << "   ✗ Відбувається 'зрізання' (object slicing)" << endl;
    cout << "   ✗ Втрачається інформація про похідний клас" << endl;
    cout << "   ✗ Доступні тільки базові методи" << endl;
    
    cout << "\n2. ВКАЗІВНИКИ (Device* ptr = &smartphone):" << endl;
    cout << "   ✓ НЕ відбувається slicing" << endl;
    cout << "   ✓ Безпечна операція" << endl;
    cout << "   ✗ Через вказівник доступні тільки базові методи" << endl;
    cout << "   ✓ Можна викликати похідні методи через downcast" << endl;
    
    cout << "\n3. ПОСИЛАННЯ (Device& ref = smartphone):" << endl;
    cout << "   ✓ НЕ відбувається slicing" << endl;
    cout << "   ✓ Безпечна операція" << endl;
    cout << "   ✗ Через посилання доступні тільки базові методи" << endl;
    cout << "   ✓ Можна викликати похідні методи через downcast" << endl;
    
    cout << "\n4. ЧОМУ ТАК ВІДБУВАЄТЬСЯ?" << endl;
    cout << "   - Компілятор визначає доступні методи на основі ТИПУ змінної" << endl;
    cout << "   - Для вказівника Device* тип - це Device, навіть якщо він" << endl;
    cout << "     вказує на Smartphone" << endl;
    cout << "   - Для справжнього поліморфізму потрібні віртуальні функції!" << endl;
    
    cout << "\n" << string(60, '=') << endl;
    cout << "Всі тести завершено!" << endl;
    cout << string(60, '=') << "\n" << endl;
    
    return 0;
}

void separator(const string& title) {
    cout << "\n" << string(60, '=') << endl;
    cout << "  " << title << endl;
    cout << string(60, '=') << "\n" << endl;
}

// Тест 1: Базова функціональність - створення об'єктів і виклик методів
void testBasicFunctionality() {
    separator("ТЕСТ 1: Базова функціональність");
    
    cout << "--- Створення Smartphone ---" << endl;
    Smartphone phone("iPhone 15", false, "+380501234567");
    phone.turnOn();
    phone.makeCall();
    phone.turnOff();
    
    cout << "\n--- Створення Tablet ---" << endl;
    Tablet tablet("iPad Pro", false, 12.9);
    tablet.turnOn();
    tablet.displayInfo();
    tablet.turnOff();
    
    cout << "\n--- Створення Speakers ---" << endl;
    Speakers speakers("JBL Charge", false, 50);
    speakers.turnOn();
    speakers.increaseVolume();
    speakers.increaseVolume();
    speakers.decreaseVolume();
    speakers.turnOff();
    
    cout << "\n--- Створення Smartwatch ---" << endl;
    Smartwatch watch("Apple Watch", false, 75);
    watch.turnOn();
    watch.monitorHeartRate();
    watch.turnOff();
    
    cout << "\n--- Виклик деструкторів (кінець області видимості) ---" << endl;
}

// Тест 2: Присвоєння об'єкта похідного типу об'єкту базового типу
void testObjectSlicing() {
    separator("ТЕСТ 2: Присвоєння об'єкта похідного типу базовому");
    
    cout << "Створюємо Smartphone:" << endl;
    Smartphone phone("Samsung Galaxy", true, "+380671111111");
    
    cout << "\nСтворюємо Device і присвоюємо йому Smartphone:" << endl;
    Device device = phone;  // Object slicing!
    
    cout << "\nПОЯСНЕННЯ:" << endl;
    cout << "При присвоєнні відбувається 'зрізання об'єкта' (object slicing)." << endl;
    cout << "Копіюється тільки базова частина Device з об'єкта Smartphone." << endl;
    cout << "Вся інформація про похідний клас (phoneNumber, методи makeCall) втрачається!" << endl;
    cout << "Викликається конструктор копіювання Device (неявний)." << endl;
    
    cout << "\nВикликаємо методи базового класу через device:" << endl;
    device.turnOn();
    device.turnOff();
    // device.makeCall(); // ПОМИЛКА! Метод makeCall() не існує в Device
    
    cout << "\nВикликаємо методи через оригінальний phone:" << endl;
    phone.makeCall();
    
    cout << "\n--- Знищення об'єктів ---" << endl;
}

// Тест 3: Вказівники - базовий вказівник на похідний об'єкт
void testPointers() {
    separator("ТЕСТ 3: Вказівники на об'єкти");
    
    cout << "Створюємо Tablet:" << endl;
    Tablet tablet("Samsung Tab", false, 10.5);
    
    cout << "\nСтворюємо вказівник Device*, який вказує на Tablet:" << endl;
    Device* devicePtr = &tablet;
    
    cout << "\nПОЯСНЕННЯ:" << endl;
    cout << "При відкритому успадкуванні вказівник базового типу може вказувати" << endl;
    cout << "на об'єкт похідного типу. Це БЕЗПЕЧНО і часто використовується." << endl;
    cout << "НА ВІДМІНУ від присвоєння об'єктів, тут НЕ відбувається slicing!" << endl;
    cout << "Вказівник просто вказує на існуючий об'єкт Tablet." << endl;
    
    cout << "\nВиклик методів базового класу через вказівник:" << endl;
    devicePtr->turnOn();
    devicePtr->turnOff();
    
    cout << "\nСпроба виклику методу похідного класу:" << endl;
    cout << "devicePtr->displayInfo(); // ПОМИЛКА КОМПІЛЯЦІЇ!" << endl;
    cout << "Причина: компілятор бачить тип вказівника (Device*), а не тип об'єкта." << endl;
    cout << "Device не має методу displayInfo()." << endl;
    
    cout << "\nРішення 1: Виклик через оригінальний об'єкт:" << endl;
    tablet.displayInfo();
    
    cout << "\nРішення 2: Явне приведення типу (downcast):" << endl;
    Tablet* tabletPtr = static_cast<Tablet*>(devicePtr);
    tabletPtr->displayInfo();
    
    cout << "\nВАЖЛИВО: Такий downcast безпечний, тільки якщо ми ВПЕВНЕНІ," << endl;
    cout << "що вказівник дійсно вказує на об'єкт типу Tablet!" << endl;
    
    cout << "\n--- Кінець функції ---" << endl;
}

// Тест 4: Посилання - базове посилання на похідний об'єкт
void testReferences() {
    separator("ТЕСТ 4: Посилання на об'єкти");
    
    cout << "Створюємо Smartwatch:" << endl;
    Smartwatch watch("Garmin Fenix", false, 68);
    
    cout << "\nСтворюємо посилання Device& на Smartwatch:" << endl;
    Device& deviceRef = watch;
    
    cout << "\nПОЯСНЕННЯ:" << endl;
    cout << "Посилання працює так само, як і вказівник:" << endl;
    cout << "- Можна присвоїти посилання базового типу об'єкт похідного типу" << endl;
    cout << "- НЕ відбувається slicing (посилання - це псевдонім оригінального об'єкта)" << endl;
    cout << "- Через посилання можна викликати ТІЛЬКИ методи базового класу" << endl;
    
    cout << "\nВиклик методів базового класу через посилання:" << endl;
    deviceRef.turnOn();
    deviceRef.turnOff();
    
    cout << "\nСпроба виклику методу похідного класу:" << endl;
    cout << "deviceRef.monitorHeartRate(); // ПОМИЛКА КОМПІЛЯЦІЇ!" << endl;
    cout << "Причина: компілятор бачить тип посилання (Device&)." << endl;
    
    cout << "\nВиклик через оригінальний об'єкт:" << endl;
    watch.monitorHeartRate();
    
    cout << "\nВиклик через приведення типу:" << endl;
    Smartwatch& watchRef = static_cast<Smartwatch&>(deviceRef);
    watchRef.monitorHeartRate();
    
    cout << "\n--- Кінець функції ---" << endl;
}

// Тест 5: Функція, що приймає базовий тип
void processDevice(Device device) {  // Передача за значенням - slicing!
    cout << "  Функція processDevice (передача за значенням):" << endl;
    device.turnOn();
    device.turnOff();
}

void processDeviceByPointer(Device* device) {
    cout << "  Функція processDeviceByPointer (передача вказівника):" << endl;
    if (device) {
        device->turnOn();
        device->turnOff();
    }
}

void processDeviceByReference(Device& device) {
    cout << "  Функція processDeviceByReference (передача посилання):" << endl;
    device.turnOn();
    device.turnOff();
}

void testFunctionParameters() {
    separator("ТЕСТ 5: Передача об'єктів у функції");
    
    cout << "Створюємо Speakers:" << endl;
    Speakers speakers("Sony", false, 30);
    
    cout << "\n1. Передача за значенням (відбувається slicing):" << endl;
    processDevice(speakers);
    
    cout << "\n2. Передача вказівника (БЕЗ slicing):" << endl;
    processDeviceByPointer(&speakers);
    
    cout << "\n3. Передача посилання (БЕЗ slicing):" << endl;
    processDeviceByReference(speakers);
    
    cout << "\nВИСНОВОК:" << endl;
    cout << "- При передачі за значенням створюється копія тільки базової частини" << endl;
    cout << "- При передачі вказівника/посилання зберігається повний об'єкт" << endl;
    cout << "- Але через базові вказівники/посилання доступні тільки базові методи" << endl;
    
    cout << "\n--- Знищення об'єктів ---" << endl;
}
// Тест 6: Масив базових вказівників на різні похідні класи
void testPolymorphicArray() {
    separator("ТЕСТ 6: Поліморфний масив (без віртуальних функцій)");
    
    cout << "Створюємо масив вказівників Device*:" << endl;
    
    Smartphone phone("Xiaomi", false, "+380931234567");
    Tablet tablet("Lenovo Tab", false, 11.0);
    Speakers speakers("Bose", false, 40);
    Smartwatch watch("Fitbit", false, 72);
    
    Device* devices[] = {&phone, &tablet, &speakers, &watch};
    
    cout << "\nВикликаємо методи через масив вказівників:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\nПристрій " << (i+1) << ":" << endl;
        devices[i]->turnOn();
        devices[i]->turnOff();
        // devices[i]->makeCall(); // ПОМИЛКА! Недоступно
    }
    
    cout << "\nПОЯСНЕННЯ:" << endl;
    cout << "Через масив базових вказівників можна зберігати різні похідні типи," << endl;
    cout << "але викликати можна тільки методи базового класу." << endl;
    cout << "Для справжнього поліморфізму потрібні ВІРТУАЛЬНІ функції!" << endl;
    
    cout << "\n--- Кінець функції ---" << endl;
}