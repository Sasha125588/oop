#include "Fish.hpp"
#include "../task-1/Point.hpp"
#include <iostream>
#include <map>

using namespace std;

const Point &getDirection(char key);

void testThing();
void testFish();
void oceanEscape();
void oceanWithSeaweed();

class Thing
{
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

char Fish::ocean[OCEAN_SIZE][OCEAN_SIZE];
int Fish::countOfLiveFish = 0;

int main()
{
  // testThing();
  // testFish();
  // oceanEscape();
  oceanWithSeaweed();

  return 0;
}

void testThing()
{
  Thing::putThing(1);

  Thing thing;
  Thing thing2;

  cout << "x" << thing.x << endl;
  cout << "y" << thing.y << endl;
  cout << "z" << Thing::z << endl;
}

void testFish()
{
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

  cout << "\nСтворено " << Fish::getCountOFLiveFish() << " риб" << endl;

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

  if (fish1.moveToPosition(Point(1, 1)))
  {
    cout << "Переміщення успішне!" << endl;
  }
  else
  {
    cout << "Переміщення не вдалося." << endl;
  }

  cout << "\nСпроба перемістити " << fish2.getName()
       << " на зайняту позицію (1, 1)" << endl;
  if (fish2.moveToPosition(Point(1, 1)))
  {
    cout << "Переміщення успішне!" << endl;
  }
  else
  {
    cout << "Переміщення не вдалося - позиція зайнята." << endl;
  }

  cout << "\nСпроба перемістити " << fish3.getName()
       << " за межі океану (10, 10)" << endl;
  if (fish3.moveToPosition(Point(10, 10)))
  {
    cout << "Переміщення успішне!" << endl;
  }
  else
  {
    cout << "Переміщення не вдалося - за межами океану." << endl;
  }

  cout << "\nОновлений океан після спроб переміщення:" << endl;
  Fish::displayOcean();

  cout << "\n=== ЗАВЕРШЕННЯ ТЕСТУВАННЯ ===" << endl;
  cout << "Кількість живих риб: " << Fish::getCountOFLiveFish() << endl;
}
void oceanEscape()
{
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
  while (true)
  {
    cout << "\nХід #" << ++moves << ". Ваш хід > ";
    cin >> key;

    if (key == 'q' || key == 'Q')
    {
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
        Fish::getOcean()[newSharkPos.getY()][newSharkPos.getX()] == 'S')
    {

      // Пробуємо рух тільки по X або тільки по Y
      Point moveX(directMove.getX(), 0);
      Point moveY(0, directMove.getY());

      Point posX = sharkPos + moveX;
      Point posY = sharkPos + moveY;

      // Перевіряємо який з варіантів руху можливий
      if (posX.getX() >= 0 && posX.getX() < 10 && posX.getY() >= 0 &&
          posX.getY() < 10 && Fish::getOcean()[posX.getY()][posX.getX()] != 'S')
      {
        newSharkPos = posX;
      }
      else if (posY.getX() >= 0 && posY.getX() < 10 && posY.getY() >= 0 &&
               posY.getY() < 10 &&
               Fish::getOcean()[posY.getY()][posY.getX()] != 'S')
      {
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
    if ((py > 0 && Fish::getOcean()[py - 1][px] != 'S') || // вгору
        (py < 9 && Fish::getOcean()[py + 1][px] != 'S') || // вниз
        (px > 0 && Fish::getOcean()[py][px - 1] != 'S') || // вліво
        (px < 9 && Fish::getOcean()[py][px + 1] != 'S'))
    { // вправо
      surrounded = false;
    }

    if (surrounded)
    {
      cout << "\n╔════════════════════════════════╗" << endl;
      cout << "║       АКУЛА ВПІЙМАЛА ВАС!      ║" << endl;
      cout << "║  Ви протрималися " << moves << " ходів!    ║" << endl;
      cout << "╚════════════════════════════════╝" << endl;
      break;
    }
  }
}
void oceanWithSeaweed()
{
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

  while (true)
  {
    cout << "\nХід #" << ++moves << endl;
    player.displayFish();
    cin >> key;

    if (key == 'q' || key == 'Q')
    {
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

    if (moves % 3 == 0)
    {
      Fish::spawnSeaweed();
    }

    if (player.getHealth() == 0)
    {
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