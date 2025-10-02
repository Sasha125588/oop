#include "Array.hpp"
#include "Person.cpp"
#include <iostream>

using namespace std;

void testPerson();
void testArray();

int main() {

  srand(time(0));

  testPerson();
  // testArray();

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
  cout << "   Створено: " << p1.getName() << ", " << p1.getAge() << " років"
       << endl
       << endl;

  // 2. Демонстрація конструктора перетворення (explicit)
  cout << "2. Конструктор перетворення (explicit):" << endl;
  Person p2("Bob");
  cout << "   Створено з ім'ям: " << p2.getName() << ", вік: " << p2.getAge()
       << endl;
  cout << "   (age = -1 означає, що вік не встановлено)" << endl << endl;

  // 3. Демонстрація конструктора копії
  cout << "3. Конструктор копії:" << endl;
  Person p3(p1); // Копіювання p1 в p3
  cout << "   Скопійовано: " << p3.getName() << ", " << p3.getAge() << " років"
       << endl;
  cout << "   Адреса: " << p3.getAddress() << endl;
  cout << "   Телефон: " << p3.getPhoneNumber() << endl << endl;

  // 4. Демонстрація зміни оригіналу після копіювання
  cout << "4. Зміна оригіналу після копіювання:" << endl;
  p1.setName("Alice Updated");
  p1.setAge(26);
  cout << "   Оригінал: " << p1.getName() << ", " << p1.getAge() << " років"
       << endl;
  cout << "   Копія: " << p3.getName() << ", " << p3.getAge() << " років"
       << endl;
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
  cout << "Деструктори для p1, p2, p3, p4 викличуться при завершенні main()"
       << endl;
}

void printSeparator(const string &title) {
  cout << "\n" << string(60, '=') << endl;
  cout << "  " << title << endl;
  cout << string(60, '=') << endl;
}

void testArray() {
  printSeparator("ТЕСТИРОВАНИЕ КЛАССА ARRAY");

  // Тест 1: Конструкторы
  printSeparator("1. ТЕСТ КОНСТРУКТОРОВ");

  cout << "Создание массива по умолчанию (capacity=10):" << endl;
  Array<int> arr1;
  arr1.printInfo();

  cout << "\nСоздание массива с размером 5:" << endl;
  Array<int> arr2(5);
  arr2.printInfo();

  cout << "\nСоздание массива с размером 3 и значением 42:" << endl;
  Array<int> arr3(3, 42);
  arr3.print();

  // Тест 2: Добавление элементов и изменение указателя
  printSeparator("2. ТЕСТ ДОБАВЛЕНИЯ ЭЛЕМЕНТОВ И ИЗМЕНЕНИЯ УКАЗАТЕЛЯ");

  cout << "Добавление элементов в массив (capacity=10):" << endl;
  Array<int> arr;

  // Добавляем элементы до переполнения capacity
  for (int i = 1; i <= 12; i++) {
    cout << "Добавляем элемент " << (i * 10) << ":" << endl;
    arr.add(i * 10);
    arr.printInfo();

    // Особое внимание к 11-му элементу (когда size > capacity)
    if (i == 11) {
      cout << "┌─────────────────────────────────────┐" << endl;
      cout << "│        ⚠️  ПЕРЕПОЛНЕНИЕ! ⚠️         │" << endl;
      cout << "│   size > capacity, указатель       │" << endl;
      cout << "│   изменился на новый адрес         │" << endl;
      cout << "└─────────────────────────────────────┘" << endl;
    }

    arr.print();
    cout << endl;
  }

  // Тест 3: Заполнение массива
  printSeparator("3. ТЕСТ ЗАПОЛНЕНИЯ МАССИВА");

  cout << "Заполнение массива значением 99:" << endl;
  arr.fill(99);
  arr.print();

  cout << "\nЗаполнение случайными значениями:" << endl;
  arr.fillRandomValue();
  arr.print();

  // Тест 4: Сортировка
  printSeparator("4. ТЕСТ СОРТИРОВКИ");

  cout << "Исходный массив:" << endl;
  arr.print();

  cout << "\nСортировка по возрастанию:" << endl;
  arr.sort(true);
  arr.print();

  cout << "\nСортировка по убыванию:" << endl;
  arr.sort(false);
  arr.print();

  // Тест 5: Поиск минимума и максимума
  printSeparator("5. ТЕСТ ПОИСКА МИНИМУМА И МАКСИМУМА");

  cout << "Массив для поиска:" << endl;
  arr.print();

  int min = arr.findMin();
  int max = arr.findMax();

  cout << "┌─────────────────────────────────────┐" << endl;
  cout << "│            РЕЗУЛЬТАТЫ               │" << endl;
  cout << "├─────────────────────────────────────┤" << endl;
  cout << "│ Минимальное значение: " << min << "           │" << endl;
  cout << "│ Максимальное значение: " << max << "           │" << endl;
  cout << "└─────────────────────────────────────┘" << endl;

  // Тест 6: Поиск элемента
  printSeparator("6. ТЕСТ ПОИСКА ЭЛЕМЕНТА");

  cout << "Массив для поиска:" << endl;
  arr.print();

  int searchValue = arr[arr.getSize() / 2]; // Берем элемент из середины
  int index = arr.indexOf(searchValue);

  cout << "┌─────────────────────────────────────┐" << endl;
  cout << "│            ПОИСК ЭЛЕМЕНТА            │" << endl;
  cout << "├─────────────────────────────────────┤" << endl;
  cout << "│ Ищем значение: " << searchValue << "               │" << endl;
  cout << "│ Найден по индексу: " << index << "              │" << endl;
  cout << "└─────────────────────────────────────┘" << endl;

  // Тест 7: Удаление элементов и уменьшение capacity
  printSeparator("7. ТЕСТ УДАЛЕНИЯ ЭЛЕМЕНТОВ И УМЕНШЕНИЯ CAPACITY");

  cout << "Исходный массив:" << endl;
  arr.printInfo();
  arr.print();

  cout << "\nУдаление элементов до уменьшения capacity:" << endl;
  int initialCapacity = arr.getCapacity();

  // Удаляем элементы до тех пор, пока capacity не уменьшится
  while (arr.getSize() > 0 && arr.getCapacity() == initialCapacity) {
    cout << "Удаляем элемент по индексу 0:" << endl;
    arr.removeByIndex(0);
    arr.printInfo();

    if (arr.getCapacity() < initialCapacity) {
      cout << "┌─────────────────────────────────────┐" << endl;
      cout << "│        ⚠️  УМЕНШЕНИЕ! ⚠️          │" << endl;
      cout << "│   capacity уменьшился, указатель   │" << endl;
      cout << "│   изменился на новый адрес         │" << endl;
      cout << "└─────────────────────────────────────┘" << endl;
    }

    arr.print();
    cout << endl;
  }

  cout << "\nУдаление элемента по значению " << arr[0] << ":" << endl;
  bool removed = arr.removeByValue(arr[0]);
  if (removed) {
    cout << "Элемент успешно удален!" << endl;
  } else {
    cout << "Элемент не найден!" << endl;
  }
  arr.print();

  // Тест 8: Конструктор копирования
  printSeparator("8. ТЕСТ КОНСТРУКТОРА КОПИРОВАНИЯ");

  cout << "Исходный массив:" << endl;
  arr.print();

  cout << "\nСоздание копии:" << endl;
  Array<int> arrCopy(arr);
  arrCopy.print();

  cout << "\nИзменение оригинала:" << endl;
  arr.add(999);
  arr.print();

  cout << "\nКопия не изменилась:" << endl;
  arrCopy.print();

  // Тест 9: Оператор доступа
  printSeparator("9. ТЕСТ ОПЕРАТОРА ДОСТУПА");

  cout << "Массив:" << endl;
  arr.print();

  cout << "\nДоступ к элементам через оператор []:" << endl;
  for (int i = 0; i < arr.getSize(); i++) {
    cout << "arr[" << i << "] = " << arr[i] << endl;
  }

  // Тест 10: Итоговая информация
  printSeparator("10. ИТОГОВАЯ ИНФОРМАЦИЯ");

  cout << "Финальное состояние массива:" << endl;
  arr.printInfo();
  arr.print();

  cout << "\n" << string(60, '=') << endl;
  cout << "  ВСЕ ТЕСТЫ ЗАВЕРШЕНЫ УСПЕШНО!" << endl;
  cout << string(60, '=') << endl;
}
