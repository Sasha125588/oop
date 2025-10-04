#include "Fish.hpp"
#include "Point.hpp"
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

const Point &getDirection(char key);

void testThing();
void testPoint();
void testFish();
void oceanEscape();
void oceanWithSeaweed();

class Thing {
public:
  int x;
  int y;
  static int z;

public:
  Thing() { x = y = z; }
  static void putThing(int a) { z = a; }
};

int Thing::z;

char Point::lastNameOfPoint = ' ';
int Point::count = 0;

char Fish::ocean[10][10];
int Fish::countOfLiveFish = 0;

int main() {
  // testThing();
  // testPoint();
//   testFish();
//   oceanEscape();
  oceanWithSeaweed();

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
  Point point1(3, 4); // Точка A(3, 4)
  Point point2(1, 1); // Точка B(1, 1)

  cout << "1. Создание точек:" << endl;
  point1.printPoint();
  point2.printPoint();

  cout << "\n2. Вывод точек на экран:" << endl;
  point1.display();
  point2.display();

  cout << "\n3. Вычисление расстояния до начала координат:" << endl;
  cout << fixed << setprecision(2);
  cout << "Расстояние от точки " << point1.getName()
       << " до начала координат: " << point1.distanceToOrigin() << endl;
  cout << "Расстояние от точки " << point2.getName()
       << " до начала координат: " << point2.distanceToOrigin() << endl;

  cout << "\n4. Сложение двух точек:" << endl;
  Point sum = point1 + point2; // Используем оператор + вместо метода add
  cout << "Точка " << point1.getName() << "(" << point1.getX() << ", "
       << point1.getY() << ") + ";
  cout << "Точка " << point2.getName() << "(" << point2.getX() << ", "
       << point2.getY() << ") = ";
  sum.display();

  cout << "\n5. Вычитание двух точек:" << endl;
  Point diff = point1 - point2;
  cout << "Точка " << point1.getName() << "(" << point1.getX() << ", "
       << point1.getY() << ") - ";
  cout << "Точка " << point2.getName() << "(" << point2.getX() << ", "
       << point2.getY() << ") = ";
  diff.display();

  cout << "\n6. Дополнительные операции:" << endl;
  Point point3(5, 0); // Точка C(5, 0)
  Point point4(0, 3); // Точка D(0, 3)

  cout << "Точка " << point3.getName() << ": (" << point3.getX() << ", "
       << point3.getY() << ")" << endl;
  cout << "Точка " << point4.getName() << ": (" << point4.getX() << ", "
       << point4.getY() << ")" << endl;
  cout << "Расстояние от C до начала координат: " << point3.distanceToOrigin()
       << endl;
  cout << "Расстояние от D до начала координат: " << point4.distanceToOrigin()
       << endl;

  cout << "\nРезультат C + D:" << endl;
  Point result = point3.add(point4);
  result.display();

  cout << "\n7. Сравнение точек по расстоянию до начала координат:" << endl;

  Point point5(5, 5); // Точка E(5, 5) - расстояние ≈ 7.07
  Point point6(3, 4); // Точка F(3, 4) - расстояние = 5.00

  cout << "Точка " << point5.getName() << ": (" << point5.getX() << ", "
       << point5.getY() << ") - расстояние до начала: " << fixed
       << setprecision(2) << point5.distanceToOrigin() << endl;
  cout << "Точка " << point6.getName() << ": (" << point6.getX() << ", "
       << point6.getY()
       << ") - расстояние до начала: " << point6.distanceToOrigin() << endl;

  int comparison = Point::compareByDistance(point5, point6);
  if (comparison < 0) {
    cout << "Точка " << point5.getName()
         << " ближе к началу координат, чем точка " << point6.getName()
         << " (returned: " << comparison << ")" << endl;
  } else if (comparison > 0) {
    cout << "Точка " << point5.getName()
         << " дальше от начала координат, чем точка " << point6.getName()
         << " (returned: " << comparison << ")" << endl;
  } else {
    cout
        << "Точки " << point5.getName() << " и " << point6.getName()
        << " находятся на одинаковом расстоянии от начала координат (returned: "
        << comparison << ")" << endl;
  }

  cout << "\n8. Дополнительное сравнение:" << endl;
  Point point7(0, 6); // Точка G(0, 6) - расстояние = 6.0

  cout << "Точка " << point7.getName() << ": (" << point7.getX() << ", "
       << point7.getY()
       << ") - расстояние до начала: " << point7.distanceToOrigin() << endl;

  comparison = Point::compareByDistance(point7, point6);
  if (comparison < 0) {
    cout << "Точка " << point7.getName()
         << " ближе к началу координат, чем точка " << point6.getName()
         << " (returned: " << comparison << ")" << endl;
  } else if (comparison > 0) {
    cout << "Точка " << point7.getName()
         << " дальше от начала координат, чем точка " << point6.getName()
         << " (returned: " << comparison << ")" << endl;
  } else {
    cout
        << "Точки " << point7.getName() << " и " << point6.getName()
        << " находятся на одинаковом расстоянии от начала координат (returned: "
        << comparison << ")" << endl;
  }

  // Сбрасываем счетчик перед созданием большого массива точек
  cout << "\nСчетчик точек до сброса: " << Point::getCount() << endl;
  Point::resetCount();
  cout << "Счетчик точек после сброса: " << Point::getCount() << endl;

  cout << "\n9. Тестирование работы с массивом точек:" << endl;

  // Создаем массив точек с разными координатами (используем инициализацию в
  // списке)
  Point pointArray[5] = {
      Point(1, 1),  // A(1,1) - расстояние ≈ 1.41
      Point(3, 4),  // B(3,4) - расстояние = 5.00
      Point(5, 12), // C(5,12) - расстояние = 13.00
      Point(0, 7),  // D(0,7) - расстояние = 7.00
      Point(8, 6)   // E(8,6) - расстояние = 10.00
  };

  cout << "Создан массив из 5 точек:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "Точка " << pointArray[i].getName() << ": (" << pointArray[i].getX()
         << ", " << pointArray[i].getY() << ") - расстояние: " << fixed
         << setprecision(2) << pointArray[i].distanceToOrigin() << endl;
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
      Point(3, 4), // расстояние = 5.00
      Point(4, 3), // расстояние = 5.00
      Point(0, 5)  // расстояние = 5.00
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
    bigArray[i] =
        Point(i * 2, i * 3); // Точки с координатами (0,0), (2,3), (4,6), ...
  }

  cout << "Счетчик после создания массива из 10 точек: " << Point::getCount()
       << endl;

  cout << "Первые 5 точек большого массива:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "Точка " << bigArray[i].getName() << ": (" << bigArray[i].getX()
         << ", " << bigArray[i].getY() << ")" << endl;
  }

  cout << "Если нужен массив больше 26 точек, просто вызовите "
          "Point::resetCount() перед созданием!"
       << endl;
}
void testFish() {
  cout << "=== ТЕСТУВАННЯ КЛАСУ FISH ===" << endl;

  // Ініціалізуємо океан
  Fish::initializeOcean();
  cout << "Океан ініціалізований!" << endl;

  // Створюємо риб з різними координатами та здоров'ям
  Point::resetCount();

  Fish fish1("Золота рибка", 100, Point(2, 3)); // Повністю сита риба з ім'ям

  Fish fish2("Акула", 50, Point(5, 7)); // Напівголодна риба з ім'ям

  Fish fish3("Карась", 20, Point(8, 1)); // Голодна риба з ім'ям

  Fish fish4(Point(1, 9)); // Риба без імені (за замовчуванням)

  cout << "\nСтворено " << Fish::countOfLiveFish << " риб" << endl;

  // Показуємо інформацію про риб
  cout << "\n=== ІНФОРМАЦІЯ ПРО РИБ ===" << endl;
  fish1.displayFish();
  fish2.displayFish();
  fish3.displayFish();
  fish4.displayFish();

  // Розміщуємо риб в океані
  cout << "\n=== РОЗМІЩЕННЯ РИБ В ОКЕАНІ ===" << endl;
  fish1.placeInOcean();
  fish2.placeInOcean();
  fish3.placeInOcean();
  fish4.placeInOcean();

  // Показуємо океан
  Fish::displayOcean();

  // Тестуємо годування
  cout << "\n=== ГОДУВАННЯ РИБ ===" << endl;
  cout << "Годуємо fish2 на 30 одиниць:" << endl;
  fish2.feed(30);
  fish2.displayFish();

  cout << "\nГодуємо fish3 на 50 одиниць:" << endl;
  fish3.feed(50);
  fish3.displayFish();

  // Тестуємо зменшення голоду
  cout << "\n=== ЗМЕНШЕННЯ СИТОСТІ З ЧАСОМ ===" << endl;
  cout << "fish1 втрачає 20 одиниць ситості:" << endl;
  fish1.decreaseHunger(20);
  fish1.displayFish();

  // Тестуємо переміщення риби
  cout << "\n=== ПЕРЕМІЩЕННЯ РИБИ ===" << endl;
  cout << "Спроба перемістити " << fish1.getName() << " на позицію (1, 1)"
       << endl;

  if (fish1.moveToPosition(Point(1, 1))) {
    cout << "Переміщення успішне!" << endl;
  } else {
    cout << "Переміщення не вдалося." << endl;
  }

  cout << "\nСпроба перемістити " << fish2.getName()
       << " на зайняту позицію (1, 1)" << endl;
  if (fish2.moveToPosition(Point(1, 1))) {
    cout << "Переміщення успішне!" << endl;
  } else {
    cout << "Переміщення не вдалося - позиція зайнята." << endl;
  }

  cout << "\nСпроба перемістити " << fish3.getName()
       << " за межі океану (10, 10)" << endl;
  if (fish3.moveToPosition(Point(10, 10))) {
    cout << "Переміщення успішне!" << endl;
  } else {
    cout << "Переміщення не вдалося - за межами океану." << endl;
  }

  cout << "\nОновлений океан після спроб переміщення:" << endl;
  Fish::displayOcean();

  cout << "\n=== ЗАВЕРШЕННЯ ТЕСТУВАННЯ ===" << endl;
  cout << "Кількість живих риб: " << Fish::countOfLiveFish << endl;
}
void oceanEscape() {
  cout << "\n╔════════════════════════════════╗" << endl;
  cout << "║         OCEAN ESCAPE            ║" << endl;
  cout << "╠════════════════════════════════╣" << endl;
  cout << "║  Керування:                    ║" << endl;
  cout << "║    W - вгору                   ║" << endl;
  cout << "║    S - вниз                    ║" << endl;
  cout << "║    A - вліво                   ║" << endl;
  cout << "║    D - вправо                  ║" << endl;
  cout << "║    Q - вихід                   ║" << endl;
  cout << "║                                ║" << endl;
  cout << "║  Правила:                      ║" << endl;
  cout << "║    F - ваша рибка              ║" << endl;
  cout << "║    S - акула                   ║" << endl;
  cout << "║    ~ - вода                    ║" << endl;
  cout << "╚════════════════════════════════╝" << endl;

  Fish::initializeOcean();

  Fish player("Рибка-гравець", 100, Point(4, 4));
  Fish shark("Акула", 100, Point(0, 0));

  player.placeInOcean();
  shark.placeInOcean();

  cout << "\nПочаткова позиція:" << endl;
  Fish::displayOcean();

  char key;
  int moves = 0;
  while (true) {
    cout << "\nХід #" << ++moves << ". Ваш хід > ";
    cin >> key;

    if (key == 'q' || key == 'Q') {
      cout << "\n╔════════════════════════════════╗" << endl;
      cout << "║         ГРА ЗАКІНЧЕНА          ║" << endl;
      cout << "║  Ви зробили " << moves << " ходів!         ║" << endl;
      cout << "╚════════════════════════════════╝" << endl;
      break;
    }

    Point direction = getDirection(key);
    Point newPlayerPos = player.getCoordinates() + direction;

    // Перевіряємо чи не виходить за межі

    player.moveToPosition(newPlayerPos);

    // Акула рухається до гравця
    Point sharkPos = shark.getCoordinates();
    Point playerPos = player.getCoordinates();

    // Спочатку пробуємо прямий рух до гравця
    Point directMove((playerPos.getX() > sharkPos.getX())   ? 1
                     : (playerPos.getX() < sharkPos.getX()) ? -1
                                                            : 0,

                     (playerPos.getY() > sharkPos.getY())   ? 1
                     : (playerPos.getY() < sharkPos.getY()) ? -1
                                                            : 0);

    Point newSharkPos = sharkPos + directMove;

    // Якщо прямий рух неможливий (клітинка зайнята), пробуємо рухатись в обхід
    if (newSharkPos.getX() >= 0 && newSharkPos.getX() < 10 &&
        newSharkPos.getY() >= 0 && newSharkPos.getY() < 10 &&
        Fish::ocean[newSharkPos.getY()][newSharkPos.getX()] == 'S') {

      // Пробуємо рух тільки по X або тільки по Y
      Point moveX(directMove.getX(), 0);
      Point moveY(0, directMove.getY());

      Point posX = sharkPos + moveX;
      Point posY = sharkPos + moveY;

      // Перевіряємо який з варіантів руху можливий
      if (posX.getX() >= 0 && posX.getX() < 10 && posX.getY() >= 0 &&
          posX.getY() < 10 && Fish::ocean[posX.getY()][posX.getX()] != 'S') {
        newSharkPos = posX;
      } else if (posY.getX() >= 0 && posY.getX() < 10 && posY.getY() >= 0 &&
                 posY.getY() < 10 &&
                 Fish::ocean[posY.getY()][posY.getX()] != 'S') {
        newSharkPos = posY;
      }
    }

    shark.moveToPosition(newSharkPos);

    cout << "\nОкеан після ходу:" << endl;
    Fish::displayOcean();

    // Перевіряємо чи гравець оточений акулами по 4 основним напрямкам
    int px = playerPos.getX();
    int py = playerPos.getY();
    bool surrounded = true;

    // Перевіряємо тільки основні напрямки: вгору, вниз, вліво, вправо
    if ((py > 0 && Fish::ocean[py - 1][px] != 'S') || // вгору
        (py < 9 && Fish::ocean[py + 1][px] != 'S') || // вниз
        (px > 0 && Fish::ocean[py][px - 1] != 'S') || // вліво
        (px < 9 && Fish::ocean[py][px + 1] != 'S')) { // вправо
      surrounded = false;
    }

    if (surrounded) {
      cout << "\n╔════════════════════════════════╗" << endl;
      cout << "║       АКУЛА ВПІЙМАЛА ВАС!      ║" << endl;
      cout << "║  Ви протрималися " << moves << " ходів!    ║" << endl;
      cout << "╚════════════════════════════════╝" << endl;
      break;
    }
  }
}
void oceanWithSeaweed() {
  cout << "\n╔════════════════════════════════╗" << endl;
  cout << "║         OCEAN LIFE             ║" << endl;
  cout << "╠════════════════════════════════╣" << endl;
  cout << "║  Керування:                    ║" << endl;
  cout << "║    W - вгору                   ║" << endl;
  cout << "║    S - вниз                    ║" << endl;
  cout << "║    A - вліво                   ║" << endl;
  cout << "║    D - вправо                  ║" << endl;
  cout << "║    Q - вихід                   ║" << endl;
  cout << "║                                ║" << endl;
  cout << "║  Правила:                      ║" << endl;
  cout << "║    F - ваша рибка              ║" << endl;
  cout << "║    * - водорость (+20 ситості) ║" << endl;
  cout << "║    ~ - вода                    ║" << endl;
  cout << "╚════════════════════════════════╝" << endl;

  Fish::initializeOceanWithSeaweed(15);

  Fish player("Рибка-гравець", 100, Point(4, 4));
  player.placeInOcean();

  cout << "\nПочаткова позиція:" << endl;
  Fish::displayOcean();

  char key;
  int moves = 0;

  while (true) {
    cout << "\nХід #" << ++moves << endl;
    player.displayFish();
    cin >> key;

    if (key == 'q' || key == 'Q') {
      cout << "\n╔════════════════════════════════╗" << endl;
      cout << "║         ГРА ЗАКІНЧЕНА          ║" << endl;
      cout << "║  Ви зробили " << moves << " ходів!         ║" << endl;
      cout << "║  Фінальна ситість: " << player.getHealth() << "%      ║"
           << endl;
      cout << "╚════════════════════════════════╝" << endl;
      break;
    }

    Point direction = getDirection(key);
    Point newPlayerPos = player.getCoordinates() + direction;

    player.moveToPosition(newPlayerPos);

    cout << "\nОкеан після ходу:" << endl;
    Fish::displayOcean();

    if (moves % 3 == 0) {
      Fish::spawnSeaweed();
    }

    if (player.getHealth() == 0) {
      cout << "\n╔════════════════════════════════╗" << endl;
      cout << "║      ВАША РИБКА ПОМЕРЛА!       ║" << endl;
      cout << "║     від голоду :(              ║" << endl;
      cout << "║  Ви протрималися " << moves << " ходів!    ║" << endl;
      cout << "╚════════════════════════════════╝" << endl;
      break;
    }
  }
};

map<char, Point> directions = {
  {'w', Point(0, -1)}, // Вверх
  {'s', Point(0, 1)},  // Вниз
  {'a', Point(-1, 0)}, // Вліво
  {'d', Point(1, 0)},  // Вправо

};

const Point &getDirection(char key) { return directions[key]; }