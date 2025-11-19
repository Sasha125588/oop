#include <iostream>
#include "Character.hpp"
#include "Warrior.hpp"
#include "Wizard.hpp"
#include "Hero.hpp"
using namespace std;

int main()
{
    // Створення об'єкта Character
    Character character("Базовий Персонаж", 5);
    cout << "=== Character ===" << endl;
    cout << "Ім'я: " << character.getName() << endl;
    cout << "Рівень: " << character.getLevel() << endl;
    cout << endl;
    
    // Створення об'єкта Warrior
    Warrior warrior("Воїн", 10, "Меч");
    cout << "=== Warrior ===" << endl;
    cout << "Ім'я: " << warrior.getName() << endl;
    cout << "Рівень: " << warrior.getLevel() << endl;
    cout << "Зброя: " << warrior.getWeapon() << endl;
    cout << endl;
    
    // Створення об'єкта Wizard
    Wizard wizard("Чарівник", 8, "Вогняна Куля");
    cout << "=== Wizard ===" << endl;
    cout << "Ім'я: " << wizard.getName() << endl;
    cout << "Рівень: " << wizard.getLevel() << endl;
    cout << "Закляття: " << wizard.getSpell() << endl;
    cout << endl;
    
    // Створення об'єкта Hero
    // Завдяки віртуальному базовому класу Character, Hero має лише одну копію Character
    Hero hero("Герой", 15, "Легендарний Меч", "Метеоритний Дощ", 1000);
    cout << "=== Hero ===" << endl;
    cout << "Ім'я: " << hero.getName() << endl;  // Тепер можна використовувати без неоднозначності!
    cout << "Рівень: " << hero.getLevel() << endl;  // Тепер можна використовувати без неоднозначності!

    // Non-static member 'getName' found in multiple base-class subobjects of type 'Character':
    // class Hero -> Warrior -> Character
    // class Hero -> Wizard -> Characterclang(ambiguous_member_multiple_subobjects)
    
    cout << "Зброя: " << hero.getWeapon() << endl;
    cout << "Закляття: " << hero.getSpell() << endl;
    cout << "Досвід: " << hero.getExperience() << endl;
    cout << endl;
    cout << "Примітка: Завдяки віртуальному базовому класу Character," << endl;
    cout << "Hero має лише одну копію Character, тому немає неоднозначності!" << endl;
    cout << endl;
    
    // Демонстрація використання сеттерів
    cout << "=== Оновлення значень ===" << endl;
    character.setName("Оновлений Персонаж");
    character.setLevel(7);
    cout << "Character після оновлення:" << endl;
    cout << "Ім'я: " << character.getName() << endl;
    cout << "Рівень: " << character.getLevel() << endl;
    
    warrior.setWeapon("Сокира");
    cout << "Warrior зброя: " << warrior.getWeapon() << endl;
    
    wizard.setSpell("Льодова Стріла");
    cout << "Wizard закляття: " << wizard.getSpell() << endl;
    
    hero.setExperience(1500);
    cout << "Hero досвід: " << hero.getExperience() << endl;
    
    return 0;
}
