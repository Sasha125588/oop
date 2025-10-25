#pragma once
class Person {
    private:
      char* name;
      char* address;
      short age;
      char* phoneNumber;
    
    public:
      Person();
      Person(const Person &other);
      explicit Person(const char* personName);
    
      ~Person();
    
      const char* getName() const;
      void setName(const char* name);
    
      const char* getAddress() const;
      void setAddress(const char* address);
    
      short getAge() const;
      void setAge(short age);
    
      const char* getPhoneNumber() const;
      void setPhoneNumber(const char* phoneNumber);
    };