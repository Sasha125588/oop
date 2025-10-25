#include <iostream>
#include <cstring>
#include "Person.hpp"

using namespace std;

Person::Person() {
  name = new char[1];
  name[0] = '\0';

  address = new char[1];
  address[0] = '\0';
  
  age = -1;
  
  phoneNumber = new char[1];
  phoneNumber[0] = '\0';
}

Person::Person(const Person &other) {
  name = new char[strlen(other.name) + 1];
  strcpy(name, other.name);
  
  address = new char[strlen(other.address) + 1];
  strcpy(address, other.address);
  
  age = other.age;
  
  phoneNumber = new char[strlen(other.phoneNumber) + 1];
  strcpy(phoneNumber, other.phoneNumber);
}

Person::Person(const char* personName) {
  name = new char[strlen(personName) + 1];
  strcpy(name, personName);
  
  address = new char[1];
  address[0] = '\0';
  
  age = -1;
  
  phoneNumber = new char[1];
  phoneNumber[0] = '\0';
}

Person::~Person() { 
  cout << "Person " << name << " destroyed" << endl; 
  delete[] name;
  delete[] address;
  delete[] phoneNumber;
}

const char* Person::getName() const { return name; }
void Person::setName(const char* name) { 
  delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

const char* Person::getAddress() const { return address; }
void Person::setAddress(const char* address) { 
  delete[] this->address;
  this->address = new char[strlen(address) + 1];
  strcpy(this->address, address);
}

short Person::getAge() const { return age; }
void Person::setAge(short age) { this->age = age; }

const char* Person::getPhoneNumber() const { return phoneNumber; }
void Person::setPhoneNumber(const char* phoneNumber) { 
  delete[] this->phoneNumber;
  this->phoneNumber = new char[strlen(phoneNumber) + 1];
  strcpy(this->phoneNumber, phoneNumber);
}
