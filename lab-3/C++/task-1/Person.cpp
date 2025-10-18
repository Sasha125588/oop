#include "Person.hpp"

Person::Person(Person &other) {
  name = other.name;
  address = other.address;
  age = other.age;
  phoneNumber = other.phoneNumber;
}

Person::Person(const string &personName) {
  name = personName;
  address = "";
  age = -1;
  phoneNumber = "";
}

Person::~Person() { cout << "Person " << name << " destroyed" << endl; }

string Person::getName() const { return name; }
void Person::setName(string name) { this->name = name; }

string Person::getAddress() const { return address; }
void Person::setAddress(string address) { this->address = address; }

short Person::getAge() const { return age; }
void Person::setAge(short age) { this->age = age; }

string Person::getPhoneNumber() const { return phoneNumber; }
void Person::setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
