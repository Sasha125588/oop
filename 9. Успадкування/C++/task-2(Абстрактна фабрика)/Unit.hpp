#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Unit {
    private:
        string name;
        int health;
        int damage;
        int dodgePercent;
        bool isAlive;

        void die() {
            isAlive = false;
            health = 0;
            cout << "💀 " << name << " загинув у бою!" << endl;
        }

    public:
    Unit(const string& name, int health, int damage, int dodgePercent)
        : name(name), health(health), damage(damage), 
          dodgePercent(dodgePercent), isAlive(true) {
        cout << name << " [HP:" << health << " ATK:" << damage << " DODGE:" << dodgePercent << "%]" << endl;
    }

    virtual ~Unit() {
        cout << "🗑️  Видалено воїна: " << name << endl;
    }

    void attack(Unit& other) {
        if (!isAlive) {
            cout << "❌ " << name << " не може атакувати - загинув!" << endl;
            return;
        }
        
        if (!other.isAlive) {
            cout << "❌ " << other.name << " вже мертвий!" << endl;
            return;
        }
        
        cout << "\n⚔️  " << name << " атакує " << other.name 
             << " (пошкодження: " << damage << ")" << endl;
        other.takeDamage(damage);
    }

    void takeDamage(int incomingDamage) {
        if (!isAlive) {
            cout << "   ⚰️  " << name << " вже мертвий!" << endl;
            return;
        }
        
        int dodgeRoll = rand() % 100 + 1;
        if (dodgeRoll <= dodgePercent) {
            cout << "   🌪️  " << name << " ухилився від атаки! (Roll: " << dodgeRoll << "/" << dodgePercent << "%)" << endl;
            return;
        }
        
        health -= incomingDamage;
        cout << "   💥 " << name << " отримав " << incomingDamage << " пошкодження! ";
        
        if (health <= 0) {
            health = 0;
            cout << "[HP: " << health << "] ";
            die();
        } else {
            cout << "[HP: " << health << "]" << endl;
        }
    }

    void showStatus() const {
        cout << "📊 " << name << ": ";
        if (!isAlive) {
            cout << "💀 МЕРТВИЙ" << endl;
            return;
        }
        
        cout << "] " << health << " HP"
             << " | ATK:" << damage << " | DODGE:" << dodgePercent << "%" << endl;
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getDodgePercent() const { return dodgePercent; }
    bool getIsAlive() const { return isAlive; }

    void setName(const string& newName) { name = newName; }
};