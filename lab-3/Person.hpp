#pragma once

#include <iostream>

using namespace std;

class Person {
    private:
      string name;
      string address;
      short age;
      string phoneNumber;
    
    public:
      Person() = default;
      Person(Person &other);
      explicit Person(const string &personName);
    
      ~Person();
    
      string getName() const;
      void setName(string name);
    
      string getAddress() const;
      void setAddress(string address);
    
      short getAge() const;
      void setAge(short age);
    
      string getPhoneNumber() const;
      void setPhoneNumber(string phoneNumber);
    };