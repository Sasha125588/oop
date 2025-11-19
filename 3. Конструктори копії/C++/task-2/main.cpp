#include "Array.hpp"
#include <iostream>

using namespace std;

void testArray();

int main()
{
  srand(time(0));

  testArray();

  return 0;
}

void printSeparator(const string &title)
{
  cout << "\n"
       << string(60, '=') << endl;
  cout << "  " << title << endl;
  cout << string(60, '=') << endl;
}

void testArray()
{
  printSeparator("ТЕСТУВАННЯ КЛАСУ ARRAY");

  // Тест 1: Конструктори
  printSeparator("1. ТЕСТ КОНСТРУКТОРІВ");

  cout << "Створення масиву за замовчуванням (capacity=10):" << endl;
  Array<int> arr1;
  arr1.printInfo();

  cout << "\nСтворення масиву з розміром 5:" << endl;
  Array<int> arr2(5);
  arr2.printInfo();

  cout << "\nСтворення масиву з розміром 3 і значенням 42:" << endl;
  Array<int> arr3(3, 42);
  arr3.print();

  // Тест 2: Додавання елементів і зміна вказівника
  printSeparator("2. ТЕСТ ДОДАВАННЯ ЕЛЕМЕНТІВ І ЗМІНИ ВКАЗІВНИКА");

  cout << "Додавання елементів у масив (capacity=10):" << endl;
  Array<int> arr;

  // Додаємо елементи до переповнення capacity
  for (int i = 1; i <= 12; i++)
  {
    cout << "Додаємо елемент " << (i * 10) << ":" << endl;
    arr.add(i * 10);
    arr.printInfo();

    // Особлива увага до 11-го елемента (коли size > capacity)
    if (i == 11)
    {
      cout << "┌─────────────────────────────────────┐" << endl;
      cout << "│        ⚠️  ПЕРЕПОВНЕННЯ! ⚠️        │" << endl;
      cout << "│   size > capacity, вказівник       │" << endl;
      cout << "│   змінився на нову адресу          │" << endl;
      cout << "└─────────────────────────────────────┘" << endl;
    }

    arr.print();
    cout << endl;
  }

  // Тест 3: Заповнення масиву
  printSeparator("3. ТЕСТ ЗАПОВНЕННЯ МАСИВУ");

  cout << "Заповнення масиву значенням 99:" << endl;
  arr.fill(99);
  arr.print();

  cout << "\nЗаповнення випадковими значеннями:" << endl;
  arr.fillRandomValue();
  arr.print();

  // Тест 4: Сортування
  printSeparator("4. ТЕСТ СОРТУВАННЯ");

  cout << "Початковий масив:" << endl;
  arr.print();

  cout << "\nСортування за зростанням:" << endl;
  arr.sort(true);
  arr.print();

  cout << "\nСортування за спаданням:" << endl;
  arr.sort(false);
  arr.print();

  // Тест 5: Пошук мінімуму і максимуму
  printSeparator("5. ТЕСТ ПОШУКУ МІНІМУМУ І МАКСИМУМУ");

  cout << "Масив для пошуку:" << endl;
  arr.print();

  int min = arr.findMin();
  int max = arr.findMax();

  cout << "┌─────────────────────────────────────┐" << endl;
  cout << "│             РЕЗУЛЬТАТИ             │" << endl;
  cout << "├─────────────────────────────────────┤" << endl;
  cout << "│ Мінімальне значення: " << min << "           │" << endl;
  cout << "│ Максимальне значення: " << max << "          │" << endl;
  cout << "└─────────────────────────────────────┘" << endl;

  // Тест 6: Пошук елемента
  printSeparator("6. ТЕСТ ПОШУКУ ЕЛЕМЕНТА");

  cout << "Масив для пошуку:" << endl;
  arr.print();

  int searchValue = arr[arr.getSize() / 2]; // Беремо елемент із середини
  int index = arr.indexOf(searchValue);

  cout << "┌─────────────────────────────────────┐" << endl;
  cout << "│             ПОШУК ЕЛЕМЕНТА         │" << endl;
  cout << "├─────────────────────────────────────┤" << endl;
  cout << "│ Шукаємо значення: " << searchValue << "              │" << endl;
  cout << "│ Знайдено за індексом: " << index << "              │" << endl;
  cout << "└─────────────────────────────────────┘" << endl;

  // Тест 7: Видалення елементів і зменшення capacity
  printSeparator("7. ТЕСТ ВИДАЛЕННЯ ЕЛЕМЕНТІВ І ЗМЕНШЕННЯ CAPACITY");

  cout << "Початковий масив:" << endl;
  arr.printInfo();
  arr.print();

  cout << "\nВидалення елементів до зменшення capacity:" << endl;
  int initialCapacity = arr.getCapacity();

  // Видаляємо елементи, поки capacity не зменшиться
  while (arr.getSize() > 0 && arr.getCapacity() == initialCapacity)
  {
    cout << "Видаляємо елемент за індексом 0:" << endl;
    arr.removeByIndex(0);
    arr.printInfo();

    if (arr.getCapacity() < initialCapacity)
    {
      cout << "┌─────────────────────────────────────┐" << endl;
      cout << "│        ⚠️  ЗМЕНШЕННЯ! ⚠️          │" << endl;
      cout << "│   capacity зменшився, вказівник    │" << endl;
      cout << "│   змінився на нову адресу          │" << endl;
      cout << "└─────────────────────────────────────┘" << endl;
    }

    arr.print();
    cout << endl;
  }

  cout << "\nВидалення елемента зі значенням " << arr[0] << ":" << endl;
  bool removed = arr.removeByValue(arr[0]);
  if (removed)
  {
    cout << "Елемент успішно видалено!" << endl;
  }
  else
  {
    cout << "Елемент не знайдено!" << endl;
  }
  arr.print();

  // Тест 8: Конструктор копіювання
  printSeparator("8. ТЕСТ КОНСТРУКТОРА КОПІЮВАННЯ");

  cout << "Початковий масив:" << endl;
  arr.print();

  cout << "\nСтворення копії:" << endl;
  Array<int> arrCopy(arr);
  arrCopy.print();

  cout << "\nЗміна оригіналу:" << endl;
  arr.add(999);
  arr.print();

  cout << "\nКопія не змінилась:" << endl;
  arrCopy.print();

  // Тест 9: Оператор доступу
  printSeparator("9. ТЕСТ ОПЕРАТОРА ДОСТУПУ");

  cout << "Масив:" << endl;
  arr.print();

  cout << "\nДоступ до елементів через оператор []:" << endl;
  for (int i = 0; i < arr.getSize(); i++)
  {
    cout << "arr[" << i << "] = " << arr[i] << endl;
  }

  // Тест 10: Підсумкова інформація
  printSeparator("10. ПІДСУМКОВА ІНФОРМАЦІЯ");

  cout << "Кінцевий стан масиву:" << endl;
  arr.printInfo();
  arr.print();

  cout << "\n"
       << string(60, '=') << endl;
  cout << "  УСІ ТЕСТИ УСПІШНО ЗАВЕРШЕНІ!" << endl;
  cout << string(60, '=') << endl;
}
