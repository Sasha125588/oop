#include "Archer.hpp"
#include "Mage.hpp"
#include "Swordsman.hpp"
#include "Unit.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>

using namespace std;

void waitForSpace();
Unit* createRandomUnit(const string& teamPrefix, int number);
bool isTeamDefeated(Unit* team[], int size);
int countAlive(Unit* team[], int size);
void showTeamStatus(const string& teamName, Unit* team[], int size);
Unit* getRandomAliveUnit(Unit* team[], int size);

void separator(const string& text = "") {
    cout << "\n" << string(70, '=') << endl;
    if (!text.empty()) {
        cout << "  " << text << endl;
        cout << string(70, '=') << endl;
    }
}

int main() {
    srand(time(NULL));
    
    cout << "\n";
    cout << "████████████████████████████████████████████████████████████████████" << endl;
    cout << "█                                                                  █" << endl;
    cout << "█                    ⚔️  БИТВА ГЕРОЇВ ⚔️                          █" << endl;
    cout << "█                                                                  █" << endl;
    cout << "████████████████████████████████████████████████████████████████████" << endl;
    
    const int TEAM_SIZE = 3;
    Unit* radiantTeam[TEAM_SIZE]; // сили світла
    Unit* direTeam[TEAM_SIZE]; // сили тьми
    
    separator("ФОРМУВАННЯ КОМАНД");
    
    cout << "\n🔵 СИЛИ СВІТЛА (Radiant):" << endl;
    for (int i = 0; i < TEAM_SIZE; i++) {
        cout << "   Боєць " << (i + 1) << ": ";
        radiantTeam[i] = createRandomUnit("Radiant", i + 1);
    }
    
    cout << "\n🔴 СИЛИ ТЬМИ (Dire):" << endl;
    for (int i = 0; i < TEAM_SIZE; i++) {
        cout << "   Боєць " << (i + 1) << ": ";
        direTeam[i] = createRandomUnit("Dire", i + 1);
    }
    
    separator();
    cout << "\nКоманди сформовані! Битва починається!\n" << endl;
    
    waitForSpace();
    
    separator("⚔️  ПОЧАТОК БИТВИ ⚔️");
    
    // Відображення початкового стану команд
    showTeamStatus("🔵 СИЛИ СВІТЛА", radiantTeam, TEAM_SIZE);
    showTeamStatus("🔴 СИЛИ ТЬМИ", direTeam, TEAM_SIZE);
    
    waitForSpace();
    
    int round = 1;
    bool radiantTurn = true; // true - ходить Radiant, false - ходить Dire
    
    // Основний цикл бою
    while (!isTeamDefeated(radiantTeam, TEAM_SIZE) && !isTeamDefeated(direTeam, TEAM_SIZE)) {
        separator("РАУНД " + to_string(round));
        
        cout << "🔵 Живих бійців (Radiant): " << countAlive(radiantTeam, TEAM_SIZE) << "/" << TEAM_SIZE << endl;
        cout << "🔴 Живих бійців (Dire): " << countAlive(direTeam, TEAM_SIZE) << "/" << TEAM_SIZE << endl;
        
        // Визначаємо хто атакує і хто захищається
        Unit* attacker;
        Unit* defender;
        string attackerTeam, defenderTeam;
        
        if (radiantTurn) {
            attacker = getRandomAliveUnit(radiantTeam, TEAM_SIZE);
            defender = getRandomAliveUnit(direTeam, TEAM_SIZE);
            attackerTeam = "🔵 СВІТЛА";
            defenderTeam = "🔴 ТЬМИ";
        } else {
            attacker = getRandomAliveUnit(direTeam, TEAM_SIZE);
            defender = getRandomAliveUnit(radiantTeam, TEAM_SIZE);
            attackerTeam = "🔴 СВІТЛА";
            defenderTeam = "🔵 ТЬМИ";
        }
        
        if (!attacker || !defender) {
            break;
        }
        
        cout << "\n" << "сили " << attackerTeam << " атакують!" << endl;
        
        // Атака
        attacker->attack(*defender);
        
        // Перемикаємо черговість
        radiantTurn = !radiantTurn;
        round++;
        
        waitForSpace();
    }
    
    separator("⭐ РЕЗУЛЬТАТИ БИТВИ ⭐");
    
    // Визначення переможця
    bool radiantWon = !isTeamDefeated(radiantTeam, TEAM_SIZE);
    bool direWon = !isTeamDefeated(direTeam, TEAM_SIZE);
    
    cout << "\n";
    if (radiantWon) {
        cout << "🎉🎉🎉 ПЕРЕМОГА 🔵 СИЛ СВІТЛА! 🎉🎉🎉" << endl;
        cout << "\n🏆 Живих героїв: " << countAlive(radiantTeam, TEAM_SIZE) << "/" << TEAM_SIZE << endl;
    } else if (direWon) {
        cout << "🎉🎉🎉 ПЕРЕМОГА 🔴 СИЛ ТЬМИ! 🎉🎉🎉" << endl;
        cout << "\n🏆 Живих героїв: " << countAlive(direTeam, TEAM_SIZE) << "/" << TEAM_SIZE << endl;
    } else {
        cout << "⚖️  НІЧИЯ! Обидві команди знищені!" << endl;
    }
    
    cout << "\nВсього раундів: " << (round - 1) << endl;
    
    separator("ФІНАЛЬНИЙ СТАН КОМАНД");
    showTeamStatus("🔵 СИЛИ СВІТЛА", radiantTeam, TEAM_SIZE);
    showTeamStatus("🔴 СИЛИ ТЬМИ", direTeam, TEAM_SIZE);
    
    separator();
    cout << "\nБитва завершена!\n" << endl;
    
    for (int i = 0; i < TEAM_SIZE; i++) {
        delete radiantTeam[i];
        delete direTeam[i];
    }
    
    return 0;
}


void waitForSpace() {
    cout << "\n[Натисніть ПРОБІЛ для продовження...]";
    getchar();
    cout << "\n" << endl;
}

Unit* createRandomUnit(const string& teamPrefix, int number) {
    int type = rand() % 3;
    string name = teamPrefix + " #" + to_string(number);
    
    switch (type) {
        case 0:
            cout << "🏹 ";
            return new Archer(name);
        case 1:
            cout << "🗡️  ";
            return new Swordsman(name);
        case 2:
            cout << "🔮 ";
            return new Mage(name);
        default:
            return new Archer(name);
    }
}

bool isTeamDefeated(Unit* team[], int size) {
    for (int i = 0; i < size; i++) {
        if (team[i]->getIsAlive()) {
            return false;
        }
    }
    return true;
}

int countAlive(Unit* team[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (team[i]->getIsAlive()) count++;
    }
    return count;
}

void showTeamStatus(const string& teamName, Unit* team[], int size) {
    cout << "\n📋 " << teamName << ":" << endl;
    for (int i = 0; i < size; i++) {
        cout << "   ";
        team[i]->showStatus();
    }
}

Unit* getRandomAliveUnit(Unit* team[], int size) {
    vector<int> aliveIndices;
    for (int i = 0; i < size; i++) {
        if (team[i]->getIsAlive()) {
            aliveIndices.push_back(i);
        }
    }
    
    if (aliveIndices.empty()) return nullptr;
    
    int randomIndex = aliveIndices[rand() % aliveIndices.size()];
    return team[randomIndex];
}