#include "Point.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

void testPoint();

char Point::lastNameOfPoint = '@';
int Point::count = 0;

int main()
{
  testPoint();

  return 0;
}

void testPoint()
{
  cout << "=== Тестування класу Point ===" << endl
       << endl;

  // Створення точок
  Point point1(3, 4); // Точка A(3, 4)
  Point point2(1, 1); // Точка B(1, 1)

  cout << "1. Створення точок:" << endl;
  point1.printPoint();
  point2.printPoint();

  cout << "\n2. Виведення точок на екран:" << endl;
  point1.display();
  point2.display();

  cout << "\n3. Обчислення відстані до початку координат:" << endl;
  cout << fixed << setprecision(2);
  cout << "Відстань від точки " << point1.getName()
       << " до початку координат: " << point1.distanceToOrigin() << endl;
  cout << "Відстань від точки " << point2.getName()
       << " до початку координат: " << point2.distanceToOrigin() << endl;

  cout << "\n4. Додавання двох точок:" << endl;
  Point sum = point1 + point2; // Використовуємо оператор + замість методу add
  cout << "Точка " << point1.getName() << "(" << point1.getX() << ", "
       << point1.getY() << ") + ";
  cout << "Точка " << point2.getName() << "(" << point2.getX() << ", "
       << point2.getY() << ") = ";
  sum.display();

  cout << "\n5. Віднімання двох точок:" << endl;
  Point diff = point1 - point2;
  cout << "Точка " << point1.getName() << "(" << point1.getX() << ", "
       << point1.getY() << ") - ";
  cout << "Точка " << point2.getName() << "(" << point2.getX() << ", "
       << point2.getY() << ") = ";
  diff.display();

  cout << "\n6. Додаткові операції:" << endl;
  Point point3(5, 0); // Точка C(5, 0)
  Point point4(0, 3); // Точка D(0, 3)

  cout << "Точка " << point3.getName() << ": (" << point3.getX() << ", "
       << point3.getY() << ")" << endl;
  cout << "Точка " << point4.getName() << ": (" << point4.getX() << ", "
       << point4.getY() << ")" << endl;
  cout << "Відстань від C до початку координат: " << point3.distanceToOrigin()
       << endl;
  cout << "Відстань від D до початку координат: " << point4.distanceToOrigin()
       << endl;

  cout << "\nРезультат C + D:" << endl;
  Point result = point3.add(point4);
  result.display();

  cout << "\n7. Порівняння точок за відстанню до початку координат:" << endl;

  Point point5(5, 5); // Точка E(5, 5) - відстань ≈ 7.07
  Point point6(3, 4); // Точка F(3, 4) - відстань = 5.00

  cout << "Точка " << point5.getName() << ": (" << point5.getX() << ", "
       << point5.getY() << ") - відстань до початку: " << fixed
       << setprecision(2) << point5.distanceToOrigin() << endl;
  cout << "Точка " << point6.getName() << ": (" << point6.getX() << ", "
       << point6.getY()
       << ") - відстань до початку: " << point6.distanceToOrigin() << endl;

  int comparison = Point::compareByDistance(point5, point6);
  if (comparison < 0)
  {
    cout << "Точка " << point5.getName()
         << " ближче до початку координат, ніж точка " << point6.getName()
         << " (повернуто: " << comparison << ")" << endl;
  }
  else if (comparison > 0)
  {
    cout << "Точка " << point5.getName()
         << " далі від початку координат, ніж точка " << point6.getName()
         << " (повернуто: " << comparison << ")" << endl;
  }
  else
  {
    cout
        << "Точки " << point5.getName() << " і " << point6.getName()
        << " знаходяться на однаковій відстані від початку координат (повернуто: "
        << comparison << ")" << endl;
  }

  cout << "\n8. Додаткове порівняння:" << endl;
  Point point7(0, 6); // Точка G(0, 6) - відстань = 6.0

  cout << "Точка " << point7.getName() << ": (" << point7.getX() << ", "
       << point7.getY()
       << ") - відстань до початку: " << point7.distanceToOrigin() << endl;

  comparison = Point::compareByDistance(point7, point6);
  if (comparison < 0)
  {
    cout << "Точка " << point7.getName()
         << " ближче до початку координат, ніж точка " << point6.getName()
         << " (повернуто: " << comparison << ")" << endl;
  }
  else if (comparison > 0)
  {
    cout << "Точка " << point7.getName()
         << " далі від початку координат, ніж точка " << point6.getName()
         << " (повернуто: " << comparison << ")" << endl;
  }
  else
  {
    cout
        << "Точки " << point7.getName() << " і " << point6.getName()
        << " знаходяться на однаковій відстані від початку координат (повернуто: "
        << comparison << ")" << endl;
  }

  // Скидаємо лічильник перед створенням великого масиву точок
  cout << "\nЛічильник точок до скидання: " << Point::getCount() << endl;
  Point::resetCount();
  cout << "Лічильник точок після скидання: " << Point::getCount() << endl;

  cout << "\n9. Тестування роботи з масивом точок:" << endl;

  // Створюємо масив точок із різними координатами (використовуємо список ініціалізації)
  Point pointArray[5] = {
      Point(1, 1),  // A(1,1) - відстань ≈ 1.41
      Point(3, 4),  // B(3,4) - відстань = 5.00
      Point(5, 12), // C(5,12) - відстань = 13.00
      Point(0, 7),  // D(0,7) - відстань = 7.00
      Point(8, 6)   // E(8,6) - відстань = 10.00
  };

  cout << "Створено масив із 5 точок:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "Точка " << pointArray[i].getName() << ": (" << pointArray[i].getX()
         << ", " << pointArray[i].getY() << ") - відстань: " << fixed
         << setprecision(2) << pointArray[i].distanceToOrigin() << endl;
  }

  // Знаходимо найближчу точку до початку координат
  cout << "\nПошук найближчої точки до початку координат:" << endl;
  Point closest = Point::findClosestToOrigin(pointArray, 5);
  cout << "Найближча точка: ";
  closest.display();
  cout << "Відстань: " << closest.distanceToOrigin() << endl;

  // Знаходимо найвіддаленішу точку від початку координат
  cout << "\nПошук найвіддаленішої точки від початку координат:" << endl;
  Point farthest = Point::findClosestToOrigin(pointArray, 5);
  cout << "Найвіддаленіша точка: ";
  farthest.display();
  cout << "Відстань: " << farthest.distanceToOrigin() << endl;

  cout << "\n10. Тестування з екстремальними випадками:" << endl;

  // Масив з однаковими відстанями
  Point sameDistanceArray[3] = {
      Point(3, 4), // відстань = 5.00
      Point(4, 3), // відстань = 5.00
      Point(0, 5)  // відстань = 5.00
  };

  cout << "Масив точок з однаковою відстанню до початку координат:" << endl;
  Point::displayAll(sameDistanceArray, 3);

  cout << "Найближча (перша знайдена): ";
  Point closestSame = Point::findClosestToOrigin(sameDistanceArray, 3);
  closestSame.display();

  cout << "Найвіддаленіша (перша знайдена): ";
  Point farthestSame = Point::findClosestToOrigin(sameDistanceArray, 3);
  farthestSame.display();

  cout << "\n11. Тест із великим масивом (>26 точок):" << endl;

  // Скидаємо лічильник перед створенням великого масиву
  Point::resetCount();
  cout << "Лічильник після скидання: " << Point::getCount() << endl;

  // Створюємо масив із 10 точок (це безпечно, бо у нас є A-Z)
  Point bigArray[10];
  for (int i = 0; i < 10; i++)
  {
    bigArray[i] =
        Point(i * 2, i * 3); // Точки з координатами (0,0), (2,3), (4,6), ...
  }

  cout << "Лічильник після створення масиву з 10 точок: " << Point::getCount()
       << endl;

  cout << "Перші 5 точок великого масиву:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "Точка " << bigArray[i].getName() << ": (" << bigArray[i].getX()
         << ", " << bigArray[i].getY() << ")" << endl;
  }

  cout << "Якщо потрібен масив більший за 26 точок, просто викличте "
          "Point::resetCount() перед створенням!"
       << endl;
}
