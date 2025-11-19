#pragma once

#include <string>
#include "Character.hpp"

using namespace std;

class Wizard: public virtual Character {
  private:
		string spell;

  public:
		Wizard() : Character(), spell("") {}
		
		Wizard(const string& name, size_t level, const string& spell) 
			: Character(name, level), spell(spell) {}
		
		string getSpell() const { return spell; }
		
		void setSpell(const string& spell) { this->spell = spell; }
};