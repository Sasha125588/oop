#pragma once

#include "../task-1/Animal.hpp"
#include "../task-1/Cat.hpp"
#include "../task-1/Dog.hpp"
#include "../task-1/Hamster.hpp"
#include "../task-1/Parrot.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zoo {
private:
  vector<Animal *> animals;

  Animal *createAnimalFromUserInput() {
    int choice;
    string name, breed, color, furLength;
    int age;
    bool canTalk;

    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║     Оберіть тип тваринки:              ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;
    cout << "║  1. 🐈 Кішка (Cat)                     ║" << endl;
    cout << "║  2. 🐕 Собака (Dog)                    ║" << endl;
    cout << "║  3. 🦜 Папуга (Parrot)                 ║" << endl;
    cout << "║  4. 🐹 Хом'як (Hamster)                ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Ваш вибір (1-4): ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
      cout << "❌ Невірний вибір! Спробуйте ще раз." << endl;
      return nullptr;
    }

    cout << "\n--- Базова інформація ---" << endl;
    cout << "Введіть ім'я тваринки: ";
    cin.ignore();
    getline(cin, name);

    cout << "Введіть вік (роки): ";
    cin >> age;

    Animal *newAnimal = nullptr;

    switch (choice) {
    case 1: {
      cout << "\n--- Додаткова інформація для кішки ---" << endl;
      cout << "Введіть породу: ";
      cin.ignore();
      getline(cin, breed);
      cout << "Введіть колір: ";
      getline(cin, color);

      newAnimal = new Cat(name, age, breed, color);
      cout << "\n✅ Кішку " << name << " успішно створено!" << endl;
      break;
    }
    case 2: {
        cout << "\n--- Додаткова інформація для собаки ---" << endl;
        cout << "Введіть породу: ";
        cin.ignore();
        getline(cin, breed);
        cout << "Введіть колір: ";
        getline(cin, color);
  
        newAnimal = new Dog(name, age, breed, color);
        cout << "\n✅ Собаку " << name << " успішно створено!" << endl;
        break;
      }
    case 3: {
      cout << "\n--- Додаткова інформація для папуги ---" << endl;
      cout << "Введіть колір: ";
      cin.ignore();
      getline(cin, color);
      cout << "Чи вміє говорити? (1 - так, 0 - ні): ";
      cin >> canTalk;

      newAnimal = new Parrot(name, age, color, canTalk);
      cout << "\n✅ Папугу " << name << " успішно створено!" << endl;
      break;
    }
    case 4: {
      cout << "\n--- Додаткова інформація для хом'яка ---" << endl;
      cout << "Введіть колір: ";
      cin.ignore();
      getline(cin, color);
      cout << "Введіть довжину шерсті (Short/Medium/Long): ";
      getline(cin, furLength);

      newAnimal = new Hamster(name, age, color, furLength);
      cout << "\n✅ Хом'яка " << name << " успішно створено!" << endl;
      break;
    }
    }

    return newAnimal;
  }

public:
  Zoo() {}

  Zoo(const vector<Animal*>& initialAnimals) : animals(initialAnimals) {
    cout << "📦 Завантаження тварин..." << endl;
    cout << "✅ Завантажено " << animals.size() << " тварин!\n" << endl;
  }

  ~Zoo() {
    for (auto animal : animals) {
      delete animal;
    }
  }

  void addAnimal() {
    Animal *animal = createAnimalFromUserInput();

    if (animal != nullptr) {
      animals.push_back(animal);
      cout << "🎉 Тваринку додано до зоопарку!" << endl;
    }
  }

  void addAnimal(Animal *animal) {
    if (animal != nullptr) {
      animals.push_back(animal);
    }
  }

  void removeAnimalByIndex(int index) {
    if (index < 0 || index >= static_cast<int>(animals.size())) {
      cout << "❌ Невірний індекс! Введіть число від 0 до "
           << (animals.size() - 1) << endl;
      return;
    }

    string animalName = animals[index]->getName();
    delete animals[index];
    animals.erase(animals.begin() + index);
    cout << "💰 Тваринку " << animalName << " (індекс " << index
         << ") успішно продано!" << endl;
  }

  void removeAnimalByName(const string &name) {
    for (size_t i = 0; i < animals.size(); i++) {
      if (animals[i]->getName() == name) {
        delete animals[i];
        animals.erase(animals.begin() + i);
        cout << "💰 Тваринку " << name << " успішно продано!" << endl;
        return;
      }
    }
    cout << "❌ Тваринку з ім'ям \"" << name << "\" не знайдено!" << endl;
  }

  void removeAllAnimals() {
    if (animals.empty()) {
      cout << "\n📭 Зоопарк вже порожній!" << endl;
      return;
    }

    int count = animals.size();
    for (auto animal : animals) {
      delete animal;
    }
    animals.clear();
    cout << "\n💰💰💰 Всі тваринки продані! (загалом: " << count << " тваринок)"
         << endl;
    cout << "🎉 Зоопарк тепер порожній!" << endl;
  }

  int getAnimalsCount() const { return animals.size(); }

  void showAllAnimals() const {
    if (animals.empty()) {
      cout << "\n📭 Зоопарк порожній. Додайте тваринок!" << endl;
      return;
    }

    cout << "\n╔════════════════════════════════════════════════════════════╗"
         << endl;
    cout << "║              ТВАРИНКИ У ЗООПАРКУ                           ║"
         << endl;
    cout << "╚════════════════════════════════════════════════════════════╝"
         << endl;
    cout << "\nВсього тваринок: " << animals.size() << "\n" << endl;

    for (size_t i = 0; i < animals.size(); i++) {
      cout << "🐾 Тваринка #" << i << ":" << endl;
      cout << "   Тип: ";
      animals[i]->type();
      cout << "   Звук: ";
      animals[i]->sound();
      cout << "   Інформація: ";
      animals[i]->show();
      cout << endl;
    }
  }
};
