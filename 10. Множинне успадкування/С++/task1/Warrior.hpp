#pragma once

#include <string>
#include "Character.hpp"

using namespace std;

class Warrior: public virtual Character {
  private:
		string weapon;

  public:
		Warrior() : Character(), weapon("") {}
		
		Warrior(const string& name, size_t level, const string& weapon) 
			: Character(name, level), weapon(weapon) {}
		
		string getWeapon() const { return weapon; }
		
		void setWeapon(const string& weapon) { this->weapon = weapon; }
};