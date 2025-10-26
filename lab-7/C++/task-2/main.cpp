#include <iostream>
#include "Smartphone.hpp"
#include "Charger.hpp"

using namespace std;
using enum ConnectorType;

void runTests();

int main()
{
    runTests();
    return 0;
}

void runTests() {
    cout << "========================================" << endl;
    cout << "   ТЕСТУВАННЯ СИСТЕМИ ЗАРЯДКИ" << endl;
    cout << "   СМАРТФОНІВ" << endl;
    cout << "========================================" << endl << endl;

    // ========== ТЕСТ 1: Створення смартфонів ==========
    cout << "=== ТЕСТ 1: Створення смартфонів ===" << endl;
    
    Smartphone iphone("Apple", "iPhone 15 Pro", 3274, USB_C);
    Smartphone samsung("Samsung", "Galaxy S23", 3900, USB_C);
    Smartphone oldPhone("Xiaomi", "Redmi Note 8", 4000, MICRO_USB);
    
    cout << "✓ Створено 3 смартфони:" << endl;
    cout << "  - " << iphone.getBrand() << " " << iphone.getModel() 
         << " (" << iphone.getBatteryCapacity() << " мАг, USB Type-C)" << endl;
    cout << "  - " << samsung.getBrand() << " " << samsung.getModel() 
         << " (" << samsung.getBatteryCapacity() << " мАг, USB Type-C)" << endl;
    cout << "  - " << oldPhone.getBrand() << " " << oldPhone.getModel() 
         << " (" << oldPhone.getBatteryCapacity() << " мАг, Micro USB)" << endl << endl;

    // ========== ТЕСТ 2: Створення зарядних пристроїв ==========
    cout << "=== ТЕСТ 2: Створення зарядних пристроїв ===" << endl;
    
    Charger* usbc_fast = new Charger(USB_C, 65);
    Charger* usbc_standard = new Charger(USB_C, 20);
    Charger* microusb = new Charger(MICRO_USB, 10);
    Charger* microusb_fast = new Charger(MICRO_USB, 18);
    
    cout << "✓ Створено 4 зарядні пристрої:" << endl;
    cout << "  - USB Type-C швидка зарядка (65 Вт)" << endl;
    cout << "  - USB Type-C стандартна (20 Вт)" << endl;
    cout << "  - Micro USB стандартна (10 Вт)" << endl;
    cout << "  - Micro USB швидка (18 Вт)" << endl << endl;

    // ========== ТЕСТ 3: Перевірка статусу без зарядки ==========
    cout << "=== ТЕСТ 3: Перевірка статусу без підключення ===" << endl;
    
    cout << "\nСтатус iPhone:" << endl;
    iphone.сhargerInfo();
    
    cout << "\nСтатус Samsung:" << endl;
    samsung.сhargerInfo();
    
    cout << "\nСтатус Xiaomi:" << endl;
    oldPhone.сhargerInfo();
    cout << endl;

    // ========== ТЕСТ 4: Підключення сумісних зарядних пристроїв ==========
    cout << "=== ТЕСТ 4: Підключення сумісних зарядних пристроїв ===" << endl;
    
    cout << "\nПідключаємо швидку зарядку USB-C до iPhone..." << endl;
    iphone.connectCharger(usbc_fast);
    cout << "✓ Підключено успішно" << endl;
    iphone.сhargerInfo();
    
    cout << "\nПідключаємо стандартну зарядку USB-C до Samsung..." << endl;
    samsung.connectCharger(usbc_standard);
    cout << "✓ Підключено успішно" << endl;
    samsung.сhargerInfo();
    
    cout << "\nПідключаємо швидку зарядку Micro USB до Xiaomi..." << endl;
    oldPhone.connectCharger(microusb_fast);
    cout << "✓ Підключено успішно" << endl;
    oldPhone.сhargerInfo();
    cout << endl;

    // ========== ТЕСТ 5: Спроба підключення несумісного роз'єму ==========
    cout << "=== ТЕСТ 5: Спроба підключення несумісного роз'єму ===" << endl;
    
    cout << "\nСпроба підключити Micro USB до iPhone (потрібен USB-C)..." << endl;
    Charger* wrong_charger = new Charger(MICRO_USB, 10);
    iphone.connectCharger(wrong_charger);
    cout << "Статус iPhone після спроби:" << endl;
    iphone.сhargerInfo();
    delete wrong_charger;
    
    cout << "\nСпроба підключити USB-C до Xiaomi (потрібен Micro USB)..." << endl;
    Charger* wrong_charger2 = new Charger(USB_C, 20);
    oldPhone.connectCharger(wrong_charger2);
    cout << "Статус Xiaomi після спроби:" << endl;
    oldPhone.сhargerInfo();
    delete wrong_charger2;
    cout << endl;

    // ========== ТЕСТ 6: Від'єднання зарядного пристрою ==========
    cout << "=== ТЕСТ 6: Від'єднання зарядного пристрою ===" << endl;
    
    cout << "\nСтатус Samsung перед від'єднанням:" << endl;
    samsung.сhargerInfo();
    
    cout << "\nВід'єднуємо зарядний пристрій від Samsung..." << endl;
    samsung.disconnectCharger();
    cout << "✓ Від'єднано успішно" << endl;
    
    cout << "\nСтатус Samsung після від'єднання:" << endl;
    samsung.сhargerInfo();
    cout << endl;

    // ========== ТЕСТ 7: Заміна зарядного пристрою ==========
    cout << "=== ТЕСТ 7: Заміна зарядного пристрою ===" << endl;
    
    cout << "\nПоточний стан iPhone:" << endl;
    iphone.сhargerInfo();
    
    cout << "\nЗамінюємо швидку зарядку на стандартну Micro USB (10 Вт)..." << endl;
    Charger* replacement = new Charger(USB_C, 30);
    iphone.connectCharger(replacement);
    cout << "✓ Замінено успішно" << endl;
    
    cout << "\nНовий стан iPhone:" << endl;
    iphone.сhargerInfo();
    cout << endl;

    // ========== ТЕСТ 8: Підключення стандартної Micro USB зарядки ==========
    cout << "=== ТЕСТ 8: Підключення стандартної Micro USB зарядки ===" << endl;
    
    cout << "\nПідключаємо стандартну Micro USB (10 Вт) до Xiaomi..." << endl;
    // Спочатку від'єднаємо поточну
    oldPhone.disconnectCharger();
    oldPhone.connectCharger(microusb);
    cout << "✓ Підключено успішно" << endl;
    oldPhone.сhargerInfo();
    cout << endl;

    // ========== ТЕСТ 9: Фінальний стан всіх пристроїв ==========
    cout << "=== ТЕСТ 9: Фінальний стан всіх пристроїв ===" << endl;
    
    cout << "\n📱 " << iphone.getBrand() << " " << iphone.getModel() << ":" << endl;
    iphone.сhargerInfo();
    
    cout << "\n📱 " << samsung.getBrand() << " " << samsung.getModel() << ":" << endl;
    samsung.сhargerInfo();
    
    cout << "\n📱 " << oldPhone.getBrand() << " " << oldPhone.getModel() << ":" << endl;
    oldPhone.сhargerInfo();
    cout << endl;

    cout << "========================================" << endl;
    cout << "       ТЕСТУВАННЯ ЗАВЕРШЕНО" << endl;
    cout << "========================================" << endl;
}