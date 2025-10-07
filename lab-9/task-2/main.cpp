#include "Zoo.hpp"
#include <iostream>

using namespace std;

void printMainMenu();
void clearScreen();

int main() {
    cout << "\n🎉 Ласкаво просимо до системи управління Зоопарком! 🎉\n" << endl;

    vector<Animal*> testAnimals = {
        new Cat("Мурчик", 3, "Британська", "Сірий"),
        new Dog("Рекс", 5, "Німецька вівчарка", "Коричневий"),
        new Parrot("Кеша", 7, "Зелений", true),
        new Hamster("Пухнастик", 1, "Золотистий", "Long"),
        new Cat("Мурка", 2, "Перська", "Біла"),
        new Dog("Бадді", 4, "Лабрадор", "Золотистий"),
        new Parrot("Ріо", 3, "Синій", false),
        new Hamster("Малюк", 1, "Білий", "Short"),
        new Cat("Сніжок", 1, "Сфінкс", "Рожевий"),
        new Dog("Шарик", 6, "Хаскі", "Чорно-білий")
    };

    Zoo zoo(testAnimals);
    
    int choice;
    bool running = true;

    while (running) {
        printMainMenu();
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n--- ДОДАВАННЯ НОВОЇ ТВАРИНКИ ---" << endl;
                zoo.addAnimal();
                break;
            }
            case 2: {
                zoo.showAllAnimals();
                break;
            }
            case 3: {
                if (zoo.getAnimalsCount() > 0) {
                    zoo.showAllAnimals();
                    int index;
                    cout << "\nВведіть індекс тваринки для продажу (0-" 
                         << (zoo.getAnimalsCount() - 1) << "): ";
                    cin >> index;
                    zoo.removeAnimalByIndex(index);
                } else {
                    cout << "\n📭 Зоопарк порожній!" << endl;
                }
                break;
            }
            case 4: {
                if (zoo.getAnimalsCount() > 0) {
                    string name;
                    cout << "\nВведіть ім'я тваринки для продажу: ";
                    cin.ignore();
                    getline(cin, name);
                    zoo.removeAnimalByName(name);
                } else {
                    cout << "\n📭 Зоопарк порожній!" << endl;
                }
                break;
            }
            case 5: {
                char confirm;
                cout << "\n⚠️  Ви впевнені, що хочете продати ВСІ тваринки? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    zoo.removeAllAnimals();
                } else {
                    cout << "❌ Операцію скасовано." << endl;
                }
                break;
            }
            case 6: {
                cout << "\n👋 До побачення! Дякуємо за роботу з Зоопарком!" << endl;
                cout << "📊 Загальна кількість тваринок у зоопарку: " 
                     << zoo.getAnimalsCount() << endl;
                running = false;
                break;
            }
            default: {
                cout << "\n❌ Невірний вибір! Спробуйте ще раз." << endl;
                break;
            }
        }

        if (running) {
            cout << "\nНатисніть Enter для продовження...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}

void printMainMenu() {
    cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║            🦁 ГОЛОВНЕ МЕНЮ ЗООПАРКУ 🦁               ║" << endl;
    cout << "╠════════════════════════════════════════════════════════╣" << endl;
    cout << "║  1. 🐾 Додати нову тваринку                          ║" << endl;
    cout << "║  2. 👀 Показати всіх тваринок                        ║" << endl;
    cout << "║  3. 💰 Продати тваринку за індексом                  ║" << endl;
    cout << "║  4. 💸 Продати тваринку за ім'ям                     ║" << endl;
    cout << "║  5. 💰💰 Продати ВСІ тваринки                        ║" << endl;
    cout << "║  6. 🚪 Вийти                                         ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
}
