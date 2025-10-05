#include <iostream>
#include "Driver.hpp"
#include "Vehicle.hpp"
using namespace std;

// Функция для комплексного тестирования системы
void runTests() {
    cout << "========================================" << endl;
    cout << "   ТЕСТИРОВАНИЕ СИСТЕМЫ УПРАВЛЕНИЯ" << endl;
    cout << "   ВОДИТЕЛЯМИ И ТРАНСПОРТОМ" << endl;
    cout << "========================================" << endl << endl;

    // ========== ТЕСТ 1: Создание водителей с разными категориями ==========
    cout << "=== ТЕСТ 1: Создание водителей ===" << endl;
    set<string> categoriesAB = {"A", "B"};
    set<string> categoriesB = {"B"};
    set<string> categoriesC = {"C"};
    set<string> categoriesABC = {"A", "B", "C"};

    Driver driver1("Иван Петров", 12345, categoriesAB);
    Driver driver2("Мария Сидорова", 67890, categoriesB);
    Driver driver3("Сергей Иванов", 11111, categoriesC);
    Driver driver4("Анна Кузнецова", 99999, categoriesABC);

    cout << "✓ Создано 4 водителя:" << endl;
    cout << "  - Иван Петров (категории A, B)" << endl;
    cout << "  - Мария Сидорова (категория B)" << endl;
    cout << "  - Сергей Иванов (категория C)" << endl;
    cout << "  - Анна Кузнецова (категории A, B, C)" << endl << endl;

    // ========== ТЕСТ 2: Создание транспортных средств ==========
    cout << "=== ТЕСТ 2: Создание транспортных средств ===" << endl;
    Vehicle moto1("Yamaha R1", 1001, "A");
    Vehicle car1("Toyota Camry", 2001, "B");
    Vehicle car2("Honda Civic", 2002, "B");
    Vehicle truck1("Volvo FH16", 3001, "C");
    Vehicle car3("BMW X5", 2003, "B");

    cout << "✓ Создано 5 транспортных средств:" << endl;
    cout << "  - Yamaha R1 (№1001, категория A)" << endl;
    cout << "  - Toyota Camry (№2001, категория B)" << endl;
    cout << "  - Honda Civic (№2002, категория B)" << endl;
    cout << "  - Volvo FH16 (№3001, категория C)" << endl;
    cout << "  - BMW X5 (№2003, категория B)" << endl << endl;

    // ========== ТЕСТ 3: Назначение транспорта водителям ==========
    cout << "=== ТЕСТ 3: Назначение транспорта водителям ===" << endl;
    
    cout << "Назначаем мотоцикл Yamaha водителю Иван (категория A)..." << endl;
    driver1.assignVehicle(&moto1);
    cout << "✓ Успешно" << endl << endl;

    cout << "Назначаем машину Toyota водителю Иван (категория B)..." << endl;
    driver1.assignVehicle(&car1);
    cout << "✓ Успешно" << endl << endl;

    cout << "Назначаем машину Honda водителю Мария (категория B)..." << endl;
    driver2.assignVehicle(&car2);
    cout << "✓ Успешно" << endl << endl;

    cout << "Назначаем грузовик Volvo водителю Сергей (категория C)..." << endl;
    driver3.assignVehicle(&truck1);
    cout << "✓ Успешно" << endl << endl;

    // ========== ТЕСТ 4: Проверка категорий (негативный тест) ==========
    cout << "=== ТЕСТ 4: Проверка категорий посвідчення ===" << endl;
    
    cout << "Пытаемся назначить грузовик (категория C) водителю Мария (только B)..." << endl;
    driver2.assignVehicle(&truck1);
    cout << endl;

    cout << "Пытаемся назначить мотоцикл (категория A) водителю Мария (только B)..." << endl;
    driver2.assignVehicle(&moto1);
    cout << endl;

    // ========== ТЕСТ 5: Попытка назначить один транспорт двум водителям ==========
    cout << "=== ТЕСТ 5: Попытка назначить транспорт нескольким водителям ===" << endl;
    
    cout << "Toyota уже принадлежит водителю Иван." << endl;
    cout << "Пытаемся назначить Toyota водителю Мария..." << endl;
    driver2.assignVehicle(&car1);
    cout << endl;

    cout << "Пытаемся назначить Honda водителю Анна (уже у Марии)..." << endl;
    driver4.assignVehicle(&car2);
    cout << endl;

    // ========== ТЕСТ 6: Добавление страховок ==========
    cout << "=== ТЕСТ 6: Добавление страховок ===" << endl;
    
    moto1.setInsurance("АльфаСтрах", "MOTO-2025-001", "31.12.2025", true);
    car1.setInsurance("БетаСтрах", "AUTO-2025-101", "30.06.2025", true);
    car2.setInsurance("ГаммаСтрах", "AUTO-2024-999", "15.01.2024", false);
    truck1.setInsurance("ДельтаСтрах", "TRUCK-2025-555", "31.12.2026", true);

    cout << "✓ Добавлены страховки для всех транспортных средств" << endl << endl;

    // ========== ТЕСТ 7: Вывод информации о транспорте каждого водителя ==========
    cout << "=== ТЕСТ 7: Информация о транспорте водителей ===" << endl << endl;

    driver1.printVehicles();
    driver2.printVehicles();
    driver3.printVehicles();
    driver4.printVehicles();

    // ========== ТЕСТ 8: Освобождение транспорта и переназначение ==========
    cout << "=== ТЕСТ 8: Освобождение и переназначение ===" << endl;
    
    cout << "Освобождаем Toyota от водителя Иван..." << endl;
    driver1.releaseVehicle(&car1);
    cout << "✓ Успешно" << endl << endl;

    cout << "Теперь назначаем Toyota водителю Мария..." << endl;
    driver2.assignVehicle(&car1);
    cout << "✓ Успешно" << endl << endl;

    cout << "Назначаем BMW водителю Анна..." << endl;
    driver4.assignVehicle(&car3);
    cout << "✓ Успешно" << endl << endl;

    // ========== ТЕСТ 9: Финальное состояние системы ==========
    cout << "=== ТЕСТ 9: Финальное состояние системы ===" << endl << endl;

    driver1.printVehicles();
    driver2.printVehicles();
    driver3.printVehicles();
    driver4.printVehicles();

    // ========== ТЕСТ 10: Попытка удалить несуществующий транспорт ==========
    cout << "=== ТЕСТ 10: Негативный тест - удаление ===" << endl;
    
    cout << "Пытаемся удалить BMW у водителя Иван (у него нет BMW)..." << endl;
    driver1.releaseVehicle(&car3);
    cout << endl;

    cout << "========================================" << endl;
    cout << "       ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << endl;
    cout << "========================================" << endl;
}

int main()
{
    runTests();
    return 0;
}
