#pragma once

#include "Warrior.hpp"
#include "Wizard.hpp"

class Hero: public Warrior, public Wizard  {
  private:
		size_t experience;

  public:
		Hero() : Character(), Warrior(), Wizard(), experience(0) {}
		
		Hero(const string& name, size_t level, const string& weapon,
		     const string& spell, size_t experience)
			: Character(name, level),
			  Warrior(name, level, weapon),
			  Wizard(name, level, spell),
			  experience(experience) {}
		
		size_t getExperience() const { return experience; }
		
		void setExperience(size_t experience) { this->experience = experience; }
};