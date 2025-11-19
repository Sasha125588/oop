#include <iostream>
#include <unordered_set>
#include "Driver.hpp"
#include "Vehicle.hpp"
using namespace std;

// Функція для комплексного тестування системи
void runTests() {
    cout << "========================================" << endl;
    cout << "   ТЕСТУВАННЯ СИСТЕМИ КЕРУВАННЯ" << endl;
    cout << "   ВОДІЯМИ ТА ТРАНСПОРТОМ" << endl;
    cout << "========================================" << endl << endl;

    // ========== ТЕСТ 1: Створення водіїв із різними категоріями ==========
    cout << "=== ТЕСТ 1: Створення водіїв ===" << endl;
    unordered_set<string> categoriesAB = {"A", "B"};
    unordered_set<string> categoriesB = {"B"};
    unordered_set<string> categoriesC = {"C"};
    unordered_set<string> categoriesABC = {"A", "B", "C"};

    Driver driver1("Іван Петров", 12345, categoriesAB);
    Driver driver2("Марія Сидорова", 67890, categoriesB);
    Driver driver3("Сергій Іванов", 11111, categoriesC);
    Driver driver4("Анна Кузнецова", 99999, categoriesABC);

    cout << "✓ Створено 4 водіїв:" << endl;
    cout << "  - Іван Петров (категорії A, B)" << endl;
    cout << "  - Марія Сидорова (категорія B)" << endl;
    cout << "  - Сергій Іванов (категорія C)" << endl;
    cout << "  - Анна Кузнецова (категорії A, B, C)" << endl << endl;

    // ========== ТЕСТ 2: Створення транспортних засобів ==========
    cout << "=== ТЕСТ 2: Створення транспортних засобів ===" << endl;
    Vehicle moto1("Yamaha R1", 1001, "A");
    Vehicle car1("Toyota Camry", 2001, "B");
    Vehicle toyota_test("Toyota Camry", 2001, "B");
    Vehicle car2("Honda Civic", 2002, "B");
    Vehicle truck1("Volvo FH16", 3001, "C");
    Vehicle car3("BMW X5", 2003, "B");

    cout << "✓ Створено 5 транспортних засобів:" << endl;
    cout << "  - Yamaha R1 (№1001, категорія A)" << endl;
    cout << "  - Toyota Camry (№2001, категорія B)" << endl;
    cout << "  - Honda Civic (№2002, категорія B)" << endl;
    cout << "  - Volvo FH16 (№3001, категорія C)" << endl;
    cout << "  - BMW X5 (№2003, категорія B)" << endl << endl;

    // ========== ТЕСТ 3: Призначення транспорту водіям ==========
    cout << "=== ТЕСТ 3: Призначення транспорту водіям ===" << endl;
    
    cout << "Призначаємо мотоцикл Yamaha водієві Іван (категорія A)..." << endl;
    driver1.assignVehicle(&moto1);
    cout << "✓ Успішно" << endl << endl;

    cout << "Призначаємо авто Toyota водієві Іван (категорія B)..." << endl;
    driver1.assignVehicle(&car1);
    cout << "✓ Успішно" << endl << endl;

    cout << "Призначаємо авто Honda водієві Марія (категорія B)..." << endl;
    driver2.assignVehicle(&car2);
    cout << "✓ Успішно" << endl << endl;

    cout << "Призначаємо вантажівку Volvo водієві Сергій (категорія C)..." << endl;
    driver3.assignVehicle(&truck1);
    cout << "✓ Успішно" << endl << endl;

    // ========== ТЕСТ 4: Перевірка категорій (негативний тест) ==========
    cout << "=== ТЕСТ 4: Перевірка категорій посвідчення ===" << endl;
    
    cout << "Пробуємо призначити вантажівку (категорія C) водієві Марія (лише B)..." << endl;
    driver2.assignVehicle(&truck1);
    cout << endl;

    cout << "Пробуємо призначити мотоцикл (категорія A) водієві Марія (лише B)..." << endl;
    driver2.assignVehicle(&moto1);
    cout << endl;

    // ========== ТЕСТ 5: Спроба призначити один транспорт кільком водіям ==========
    cout << "=== ТЕСТ 5: Спроба призначити транспорт кільком водіям ===" << endl;
    
    cout << "Toyota вже належить водієві Іван." << endl;
    cout << "Пробуємо призначити Toyota водієві Марія..." << endl;
    driver2.assignVehicle(&car1);
    cout << endl;

    cout << "Пробуємо призначити Honda водієві Анна (вона вже у Марії)..." << endl;
    driver4.assignVehicle(&car2);
    cout << endl;

    // ========== ТЕСТ 6: Додавання страхових полісів ==========
    cout << "=== ТЕСТ 6: Додавання страхових полісів ===" << endl;
    
    moto1.setInsurance("АльфаСтрах", "MOTO-2025-001", "31.12.2025", true);
    car1.setInsurance("БетаСтрах", "AUTO-2025-101", "30.06.2025", true);
    toyota_test.setInsurance("БетаСтрах", "AUTO-2025-101", "30.06.2025", true);
    car2.setInsurance("ГаммаСтрах", "AUTO-2024-999", "15.01.2024", false);
    truck1.setInsurance("ДельтаСтрах", "TRUCK-2025-555", "31.12.2026", true);

    cout << "✓ Додано страхові поліси для всіх транспортних засобів" << endl << endl;

    // ========== ТЕСТ 7: Виведення інформації про транспорт кожного водія ==========
    cout << "=== ТЕСТ 7: Інформація про транспорт водіїв ===" << endl << endl;

    driver1.assignVehicle(&toyota_test);

    driver1.printVehicles();
    driver2.printVehicles();
    driver3.printVehicles();
    driver4.printVehicles();

    // ========== ТЕСТ 8: Звільнення транспорту та переназначення ==========
    cout << "=== ТЕСТ 8: Звільнення та переназначення ===" << endl;
    
    cout << "Звільняємо Toyota від водія Іван..." << endl;
    driver1.releaseVehicle(&car1);
    cout << "✓ Успішно" << endl << endl;

    cout << "Тепер призначаємо Toyota водієві Марія..." << endl;
    driver2.assignVehicle(&car1);
    cout << "✓ Успішно" << endl << endl;

    cout << "Призначаємо BMW водієві Анна..." << endl;
    driver4.assignVehicle(&car3);
    cout << "✓ Успішно" << endl << endl;

    // ========== ТЕСТ 9: Фінальний стан системи ==========
    cout << "=== ТЕСТ 9: Фінальний стан системи ===" << endl << endl;

    driver1.printVehicles();
    driver2.printVehicles();
    driver3.printVehicles();
    driver4.printVehicles();

    // ========== ТЕСТ 10: Спроба видалити неіснуючий транспорт ==========
    cout << "=== ТЕСТ 10: Негативний тест - видалення ===" << endl;
    
    cout << "Пробуємо видалити BMW у водія Іван (у нього немає BMW)..." << endl;
    driver1.releaseVehicle(&car3);
    cout << endl;

    cout << "========================================" << endl;
    cout << "       ТЕСТУВАННЯ ЗАВЕРШЕНО" << endl;
    cout << "========================================" << endl;
}

int main()
{
    runTests();
    return 0;
}
