#include <iostream>
#include <iomanip>
#include "Point.hpp"

using namespace std;

void testThing();
void testPoint();

class Thing {
public:
  int x;
  int y;
  static int z;

public:
  Thing() {
    x = y = z; 
  }
  static void putThing(int a) { z = a; }
};

int Thing::z;  // This allocates memory for the static member

char Point::lastNameOfPoint = ' ';
int Point::count = 0;

int main() { 
    // testThing();
    testPoint();

    return 0;
}

void testThing() {
    Thing::putThing(1);

    Thing thing;
    Thing thing2;


    cout << "x" << thing.x << endl;
    cout << "y" << thing.y << endl;
    cout << "z" << Thing::z << endl;
}

void testPoint() {
    cout << "=== Тестирование класса Point ===" << endl << endl;
    
    // Создание точек
    Point point1(3, 4);  // Точка A(3, 4)
    Point point2(1, 1);  // Точка B(1, 1)
    
    cout << "1. Создание точек:" << endl;
    point1.printPoint();
    point2.printPoint();
    
    cout << "\n2. Вывод точек на экран:" << endl;
    point1.display();
    point2.display();
    
    cout << "\n3. Вычисление расстояния до начала координат:" << endl;
    cout << fixed << setprecision(2);
    cout << "Расстояние от точки " << point1.getName() << " до начала координат: " 
         << point1.distanceToOrigin() << endl;
    cout << "Расстояние от точки " << point2.getName() << " до начала координат: " 
         << point2.distanceToOrigin() << endl;
    
    cout << "\n4. Сложение двух точек:" << endl;
    Point sum = point1.add(point2);
    cout << "Точка " << point1.getName() << "(" << point1.getX() << ", " << point1.getY() << ") + ";
    cout << "Точка " << point2.getName() << "(" << point2.getX() << ", " << point2.getY() << ") = ";
    sum.display();
    
    cout << "\n5. Вычитание двух точек:" << endl;
    Point diff = point1 - point2;
    cout << "Точка " << point1.getName() << "(" << point1.getX() << ", " << point1.getY() << ") - ";
    cout << "Точка " << point2.getName() << "(" << point2.getX() << ", " << point2.getY() << ") = ";
    diff.display();
    
    cout << "\n6. Дополнительные операции:" << endl;
    Point point3(5, 0);  // Точка C(5, 0)
    Point point4(0, 3);  // Точка D(0, 3)
    
    cout << "Точка " << point3.getName() << ": (" << point3.getX() << ", " << point3.getY() << ")" << endl;
    cout << "Точка " << point4.getName() << ": (" << point4.getX() << ", " << point4.getY() << ")" << endl;
    cout << "Расстояние от C до начала координат: " << point3.distanceToOrigin() << endl;
    cout << "Расстояние от D до начала координат: " << point4.distanceToOrigin() << endl;
    
    cout << "\nРезультат C + D:" << endl;
    Point result = point3.add(point4);
    result.display();
    
    cout << "\n7. Сравнение точек по расстоянию до начала координат:" << endl;
    
    Point point5(5, 5);  // Точка E(5, 5) - расстояние ≈ 7.07
    Point point6(3, 4);  // Точка F(3, 4) - расстояние = 5.00
    
    cout << "Точка " << point5.getName() << ": (" << point5.getX() << ", " << point5.getY() << ") - расстояние до начала: " 
         << fixed << setprecision(2) << point5.distanceToOrigin() << endl;
    cout << "Точка " << point6.getName() << ": (" << point6.getX() << ", " << point6.getY() << ") - расстояние до начала: " 
         << point6.distanceToOrigin() << endl;
    
    int comparison = Point::compareByDistance(point5, point6);
    if (comparison < 0) {
        cout << "Точка " << point5.getName() << " ближе к началу координат, чем точка " << point6.getName() << " (returned: " << comparison << ")" << endl;
    } else if (comparison > 0) {
        cout << "Точка " << point5.getName() << " дальше от начала координат, чем точка " << point6.getName() << " (returned: " << comparison << ")" << endl;
    } else {
        cout << "Точки " << point5.getName() << " и " << point6.getName() << " находятся на одинаковом расстоянии от начала координат (returned: " << comparison << ")" << endl;
    }
    
    cout << "\n8. Дополнительное сравнение:" << endl;
    Point point7(0, 6);  // Точка G(0, 6) - расстояние = 6.0
    
    cout << "Точка " << point7.getName() << ": (" << point7.getX() << ", " << point7.getY() << ") - расстояние до начала: " 
         << point7.distanceToOrigin() << endl;
         
    comparison = Point::compareByDistance(point7, point6);
    if (comparison < 0) {
        cout << "Точка " << point7.getName() << " ближе к началу координат, чем точка " << point6.getName() << " (returned: " << comparison << ")" << endl;
    } else if (comparison > 0) {
        cout << "Точка " << point7.getName() << " дальше от начала координат, чем точка " << point6.getName() << " (returned: " << comparison << ")" << endl;
    } else {
        cout << "Точки " << point7.getName() << " и " << point6.getName() << " находятся на одинаковом расстоянии от начала координат (returned: " << comparison << ")" << endl;
    }

    // Сбрасываем счетчик перед созданием большого массива точек
    cout << "\nСчетчик точек до сброса: " << Point::getCount() << endl;
    Point::resetCount();
    cout << "Счетчик точек после сброса: " << Point::getCount() << endl;
    
    cout << "\n9. Тестирование работы с массивом точек:" << endl;
    
    // Создаем массив точек с разными координатами (используем инициализацию в списке)
    Point pointArray[5] = {
        Point(1, 1),   // A(1,1) - расстояние ≈ 1.41
        Point(3, 4),   // B(3,4) - расстояние = 5.00  
        Point(5, 12),  // C(5,12) - расстояние = 13.00
        Point(0, 7),   // D(0,7) - расстояние = 7.00
        Point(8, 6)    // E(8,6) - расстояние = 10.00
    };
    
    cout << "Создан массив из 5 точек:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Точка " << pointArray[i].getName() << ": (" 
             << pointArray[i].getX() << ", " << pointArray[i].getY() << ") - расстояние: " 
             << fixed << setprecision(2) << pointArray[i].distanceToOrigin() << endl;
    }
    
    // Находим самую близкую точку к началу координат
    cout << "\nПоиск самой близкой точки к началу координат:" << endl;
    Point closest = Point::findClosestToOrigin(pointArray, 5);
    cout << "Самая близкая точка: "; 
    closest.display();
    cout << "Расстояние: " << closest.distanceToOrigin() << endl;
    
    // Находим самую далекую точку от начала координат
    cout << "\nПоиск самой далекой точки от начала координат:" << endl;
    Point farthest = Point::findClosestToOrigin(pointArray, 5);
    cout << "Самая далекая точка: "; 
    farthest.display();
    cout << "Расстояние: " << farthest.distanceToOrigin() << endl;
    
    cout << "\n10. Тестирование с экстремальными случаями:" << endl;
    
    // Массив с одинаковыми расстояниями
    Point sameDistanceArray[3] = {
        Point(3, 4),   // расстояние = 5.00
        Point(4, 3),   // расстояние = 5.00
        Point(0, 5)    // расстояние = 5.00
    };
    
    cout << "Массив точек с одинаковым расстоянием до начала координат:" << endl;
    sameDistanceArray[0].displayAll(sameDistanceArray, 3);
    
    cout << "Самая близкая (первая встречающаяся): ";
    Point closestSame = Point::findClosestToOrigin(sameDistanceArray, 3);
    closestSame.display();
    
    cout << "Самая далекая (первая встречающаяся): ";
    Point farthestSame = Point::findClosestToOrigin(sameDistanceArray, 3);
    farthestSame.display();
    
    cout << "\n11. Тест с большим массивом (>26 точек):" << endl;
    
    // Сбрасываем счетчик перед созданием большого массива
    Point::resetCount();
    cout << "Счетчик после сброса: " << Point::getCount() << endl;
    
    // Создаем массив из 10 точек (это безопасно, так как у нас есть A-Z)
    Point bigArray[10];
    for (int i = 0; i < 10; i++) {
        bigArray[i] = Point(i * 2, i * 3);  // Точки с координатами (0,0), (2,3), (4,6), ...
    }
    
    cout << "Счетчик после создания массива из 10 точек: " << Point::getCount() << endl;
    
    cout << "Первые 5 точек большого массива:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Точка " << bigArray[i].getName() << ": (" 
             << bigArray[i].getX() << ", " << bigArray[i].getY() << ")" << endl;
    }
    
    cout << "Если нужен массив больше 26 точек, просто вызовите Point::resetCount() перед созданием!" << endl;
}