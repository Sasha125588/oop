#include <iostream>
#include <map>
#include <string>

using namespace std;

// Функція виводу меню
void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "   Облік товарів у магазині" << endl;
    cout << "========================================" << endl;
    cout << "1. Додати товар" << endl;
    cout << "2. Видалити товар" << endl;
    cout << "3. Знайти товар" << endl;
    cout << "4. Показати всі товари" << endl;
    cout << "5. Змінити кількість товару" << endl;
    cout << "0. Вийти" << endl;
    cout << "========================================" << endl;
    cout << "Ваш вибір: ";
}

// Функція додавання товару
void addProduct(map<string, int>& inventory) {
    string name;
    int quantity;
    
    cout << "\nВведіть назву товару: ";
    cin.ignore();
    getline(cin, name);
    
    if (name.empty()) {
        cout << "Помилка: назва товару не може бути порожньою!" << endl;
        return;
    }
    
    cout << "Введіть кількість: ";
    cin >> quantity;
    
    if (quantity <= 0) {
        cout << "Помилка: кількість має бути додатним числом!" << endl;
        return;
    }
    
    // Перевірка чи товар вже існує
    auto it = inventory.find(name);
    if (it == inventory.end()) {
        inventory[name] = quantity;
        cout << "✓ Товар \"" << name << "\" додано (" << quantity << " шт.)" << endl;
    }

    // Товар існує - додаємо до наявної кількості
    it->second += quantity;
    cout << "✓ Товар \"" << name << "\" оновлено. Нова кількість: " 
            << it->second << " шт." << endl;
}

// Функція видалення товару
void removeProduct(map<string, int>& inventory) {
    if (inventory.empty()) {
        cout << "\nСклад порожній. Немає товарів для видалення." << endl;
        return;
    }
    
    string name;
    cout << "\nВведіть назву товару для видалення: ";
    cin.ignore();
    getline(cin, name);
    
    auto it = inventory.find(name);
    
    if (it == inventory.end()) {
        cout << "✗ Товар \"" << name << "\" не знайдено на складі." << endl;
    }

    cout << "Видалено товар \"" << it->first << "\" (" 
            << it->second << " шт.)" << endl;
    inventory.erase(it);
    cout << "✓ Товар успішно видалено." << endl;
    
}

// Функція пошуку товару
void searchProduct(const map<string, int>& inventory) {
    if (inventory.empty()) {
        cout << "\nСклад порожній." << endl;
        return;
    }
    
    string name;
    cout << "\nВведіть назву товару для пошуку: ";
    cin.ignore();
    getline(cin, name);
    
    if (inventory.count(name) <= 0) {
        cout << "✗ Товар \"" << name << "\" не знайдено на складі." << endl;
    }

    auto it = inventory.find(name);
    cout << "\n┌─────────────────────────────────────" << endl;
    cout << "│ Товар знайдено!" << endl;
    cout << "├─────────────────────────────────────" << endl;
    cout << "│ Назва:    " << it->first << endl;
    cout << "│ Кількість: " << it->second << " шт." << endl;
    cout << "└─────────────────────────────────────" << endl;
    
}

// Функція виводу всіх товарів (використання ітераторів)
void displayAllProducts(const map<string, int>& inventory) {
    if (inventory.empty()) {
        cout << "\n┌─────────────────────────────────────┐" << endl;
        cout << "│  Склад порожній                     │" << endl;
        cout << "└─────────────────────────────────────┘" << endl;
        return;
    }
    
    cout << "\n┌─────────────────────────────────────────────────────────┐" << endl;
    cout << "│              СПИСОК ТОВАРІВ НА СКЛАДІ                  │" << endl;
    cout << "├──────┬──────────────────────────────┬──────────────────┤" << endl;
    cout << "│  №   │  Назва товару                │  Кількість (шт.) │" << endl;
    cout << "├──────┼──────────────────────────────┼──────────────────┤" << endl;
    
    int index = 1;
    int totalQuantity = 0;
    
    // Використання ітераторів для обходу map
    for (const auto& item: inventory) {
        cout << "│ " << index++ << ".   │ ";
        
        // Форматування назви (обрізаємо якщо занадто довга)
        string displayName = item.first;
        if (displayName.length() > 28) {
            displayName = displayName.substr(0, 25) + "...";
        }
        cout.width(28);
        cout << left << displayName << " │ ";
        
        // Форматування кількості
        cout.width(16);
        cout << right << item.second << " │" << endl;
        
        totalQuantity += item.second;
    }
    
    cout << "├──────┴──────────────────────────────┴──────────────────┤" << endl;
    cout << "│ Всього товарів: " << inventory.size() 
         << " | Загальна кількість: " << totalQuantity << " шт.        │" << endl;
    cout << "└─────────────────────────────────────────────────────────┘" << endl;
}

// Функція зміни кількості товару
void updateQuantity(map<string, int>& inventory) {
    if (inventory.empty()) {
        cout << "\nСклад порожній." << endl;
        return;
    }
    
    string name;
    int newQuantity;
    
    cout << "\nВведіть назву товару: ";
    cin.ignore();
    getline(cin, name);
    
    auto it = inventory.find(name);
    
    if (it == inventory.end()) {
        cout << "✗ Товар \"" << name << "\" не знайдено." << endl;
    }

    cout << "Поточна кількість: " << it->second << " шт." << endl;
    cout << "Введіть нову кількість: ";
    cin >> newQuantity;
    
    it->second = newQuantity;
    cout << "✓ Кількість товару \"" << name << "\" оновлено: " 
            << newQuantity << " шт." << endl;
}

int main() {
    map<string, int> inventory;
    int choice;
    
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║   Система обліку товарів у магазині    ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    
    inventory["Молоко"] = 50;
    inventory["Хліб"] = 30;
    inventory["Яблука"] = 100;
    inventory["Сир"] = 20;
    
    cout << "\nДемонстраційні дані завантажено." << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                removeProduct(inventory);
                break;
            case 3:
                searchProduct(inventory);
                break;
            case 4:
                displayAllProducts(inventory);
                break;
            case 5:
                updateQuantity(inventory);
                break;
            case 0:
                cout << "\n╔════════════════════════════════════════╗" << endl;
                cout << "║    Дякуємо за використання програми!   ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;
                break;
            default:
                cout << "\n✗ Невірний вибір. Спробуйте ще раз." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
