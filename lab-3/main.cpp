#include <iostream>
using namespace std;

void testPerson();

class Person {
private:
  string name;
  string address;
  short age;
  string phoneNumber;

public:
  Person() = default;
  Person(Person &other) {
    name = other.name;
    address = other.address;
    age = other.age;
    phoneNumber = other.phoneNumber;
  }
  explicit Person(const string &personName) {
    name = personName;
    address = "";
    age = -1;
    phoneNumber = "";
  }

  ~Person() { cout << "Person " << name << " destroyed" << endl; }

  string getName() const { return name; }
  void setName(string name) { this->name = name; }

  string getAddress() const { return address; }
  void setAddress(string address) { this->address = address; }

  short getAge() const { return age; }
  void setAge(short age) { this->age = age; }

  string getPhoneNumber() const { return phoneNumber; }
  void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
};

int main() {
  testPerson();

  return 0;
}

void testPerson() {
  cout << "=== Демонстрація роботи класу Person ===" << endl << endl;

  // 1. Демонстрація конструктора за замовчуванням
  cout << "1. Конструктор за замовчуванням:" << endl;
  Person p1;
  p1.setName("Alice");
  p1.setAge(25);
  p1.setAddress("Kyiv, Ukraine");
  p1.setPhoneNumber("+380123456789");
  cout << "   Створено: " << p1.getName() << ", " << p1.getAge() << " років" << endl << endl;

  // 2. Демонстрація конструктора перетворення (explicit)
  cout << "2. Конструктор перетворення (explicit):" << endl;
  Person p2("Bob");
  cout << "   Створено з ім'ям: " << p2.getName() << ", вік: " << p2.getAge() << endl;
  cout << "   (age = -1 означає, що вік не встановлено)" << endl << endl;

  // 3. Демонстрація конструктора копії
  cout << "3. Конструктор копії:" << endl;
  Person p3(p1); // Копіювання p1 в p3
  cout << "   Скопійовано: " << p3.getName() << ", " << p3.getAge() << " років" << endl;
  cout << "   Адреса: " << p3.getAddress() << endl;
  cout << "   Телефон: " << p3.getPhoneNumber() << endl << endl;

  // 4. Демонстрація зміни оригіналу після копіювання
  cout << "4. Зміна оригіналу після копіювання:" << endl;
  p1.setName("Alice Updated");
  p1.setAge(26);
  cout << "   Оригінал: " << p1.getName() << ", " << p1.getAge() << " років" << endl;
  cout << "   Копія: " << p3.getName() << ", " << p3.getAge() << " років" << endl;
  cout << "   (копія не змінилася - це глибока копія)" << endl << endl;

  // 5. Демонстрація роботи з explicit конструктором
  cout << "5. Робота з explicit конструктором:" << endl;
  // Person p4 = "Charlie";  // Це не скомпілюється через explicit
  Person p4("Charlie"); // Це працює
  cout << "   Створено: " << p4.getName() << endl << endl;

  // 6. Демонстрація деструкторів
  cout << "6. Демонстрація деструкторів:" << endl;
  {
    Person temp("Temporary Person");
    cout << "   Створено тимчасовий об'єкт: " << temp.getName() << endl;
  } // Тут викличеться деструктор для temp
  cout << "   Тимчасовий об'єкт знищено" << endl << endl;

  cout << "=== Кінець демонстрації ===" << endl;
  cout << "Деструктори для p1, p2, p3, p4 викличуться при завершенні main()" << endl;
}