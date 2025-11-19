#pragma once

#include <string>

using namespace std;

class Character {
  private:
		string name;
		size_t level;

  public:
		Character() : name(""), level(1) {}
		
		Character(const string& name, size_t level) : name(name), level(level) {}
		
		string getName() const { return name; }
		size_t getLevel() const { return level; }
		
		void setName(const string& name) { this->name = name; }
		void setLevel(size_t level) { this->level = level; }
};