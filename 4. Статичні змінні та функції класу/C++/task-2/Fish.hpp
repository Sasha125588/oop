#pragma once

#include "../task-1/Point.hpp"
#include <iostream>
#include <string>

using namespace std;

const int OCEAN_SIZE = 10;
const short MAX_HEALTH = 100;
const short MOVE_HUNGER_COST = 5;

class Fish
{
private:
  string name = "";
  Point coordinates = Point(0, 0);
  short health = 100;

  inline bool isValidPosition(int x, int y) const
  {
    return x >= 0 && x < OCEAN_SIZE && y >= 0 && y < OCEAN_SIZE;
  }

  void removeFromOcean() const
  {
    int x = coordinates.getX();
    int y = coordinates.getY();

    if (ocean[y][x] == 'F')
    {
      ocean[y][x] = '~';
      cout << "Риба " << (name.empty() ? "без імені" : name)
           << " видалена з океану на позиції (" << x << ", " << y << ")"
           << endl;
    }
  }

  static char ocean[OCEAN_SIZE][OCEAN_SIZE];
  static int countOfLiveFish;
public:
  Fish() : health(100) { countOfLiveFish++; }
  Fish(const string& name) : name(name), coordinates(0, 0), health(100) {
    countOfLiveFish++;
  }
  Fish(short health): health(health)
  {
    countOfLiveFish++;
  }

  Fish(const Point &coordinates): coordinates(coordinates), health(100)
  {
    countOfLiveFish++;
  }

  Fish(const string& name, short health): name(name), health(health)
  {
    countOfLiveFish++;
  }

  Fish(const string& name, short health, Point coordinates): name(name),
      coordinates(coordinates), health(health)
  {
    countOfLiveFish++;
  }

  ~Fish() {
    countOfLiveFish--;
    removeFromOcean();
}

  const string &getName() const { return name; }
  void setName(const string& name) { this->name = name; }

  const Point &getCoordinates() const { return coordinates; }
  void setCoordinates(const Point &coords) { coordinates = coords; }

  short getHealth() const { return health; }
  void setHealth(short newHealth)
  {
    if (newHealth >= 0 && newHealth <= MAX_HEALTH)
    {
      health = newHealth;
    }
  }

  static char (*getOcean())[OCEAN_SIZE] {
    return ocean;
  }

  static int getCountOFLiveFish() {
    return countOfLiveFish;
  }

  void feed(int foodAmount)
  {
    health += foodAmount;
    if (health > MAX_HEALTH)
      health = MAX_HEALTH;
  }

  void decreaseHunger(int amount = 5)
  {
    health -= amount;
    if (health <= 0) {
      health = 0;
      die();
    }
  }

  void die() {
    cout << "Риба " << name << " загинула від голоду! 💀" << endl;
    removeFromOcean();
}

  bool placeInOcean()
  {
    int x = coordinates.getX();
    int y = coordinates.getY();

    if (!isValidPosition(x, y))
    {
      cout << "Помилка: координати (" << x << ", " << y
           << ") поза межами океану!" << endl;
      return false;
    }

    if (ocean[y][x] == '~' || ocean[y][x] == '*')
    {
      if (ocean[y][x] == '*')
      {
        feed(10);
        cout << "Риба з'їла водорость! Ситість: " << health << endl;
      }

      ocean[y][x] = (name == "Акула" ? 'S' : 'F');
      cout << "Риба " << (name.empty() ? "без імені" : name)
           << " розміщена в океані на позиції (" << x << ", " << y << ")"
           << endl;
      return true;
    }
    else
    {
      cout << "Помилка: позиція (" << x << ", " << y << ") вже зайнята!"
           << endl;
      return false;
    }
  }

  bool moveToPosition(const Point &newPosition)
  {
    int x = newPosition.getX();
    int y = newPosition.getY();

    if (!isValidPosition(x, y))
    {
      cout << "Помилка: координати (" << x << ", " << y
           << ") поза межами океану!" << endl;
      return false;
    }

    Point oldPosition = coordinates;

    removeFromOcean();

    coordinates = newPosition;

    if (!placeInOcean())
    {
      coordinates = oldPosition;
      placeInOcean();
      return false;
    }

    decreaseHunger();

    return true;
  }

  static void displayOcean()
  {
    cout << "\n┌─────────────────────────────────────┐" << endl;
    cout << "│              ОКЕАН                  │" << endl;
    cout << "├─────────────────────────────────────┤" << endl;
    cout << "│   ";
    for (int x = 0; x < OCEAN_SIZE; x++)
    {
      cout << x << " ";
    }
    cout << "│" << endl;

    for (int y = 0; y < OCEAN_SIZE; y++)
    {
      cout << "│ " << y << " ";
      for (int x = 0; x < OCEAN_SIZE; x++)
      {
        cout << ocean[y][x] << " ";
      }
      cout << "│" << endl;
    }
    cout << "└─────────────────────────────────────┘" << endl;
    cout << "Легенда: F - риба, S - акула, * - водорость, ~ - вода" << endl;
  }

  static void initializeOcean()
  {
    for (int y = 0; y < OCEAN_SIZE; y++)
    {
      for (int x = 0; x < OCEAN_SIZE; x++)
      {
        ocean[y][x] = '~';
      }
    }
  }

  static void initializeOceanWithSeaweed(int seaweedCount = 10)
  {
    initializeOcean();

    int placedSeaweed = 0;
    while (placedSeaweed < seaweedCount)
    {
      int x = rand() % OCEAN_SIZE;
      int y = rand() % OCEAN_SIZE;

      if (ocean[y][x] == '~')
      {
        ocean[y][x] = '*';
        placedSeaweed++;
      }
    }
  }

  static void spawnSeaweed()
  {
    int x = rand() % OCEAN_SIZE;
    int y = rand() % OCEAN_SIZE;

    if (ocean[y][x] == '~')
    {
      ocean[y][x] = '*';
    }
  }

  void displayFish() const
  {
    cout << "┌─────────────────────────────────────┐" << endl;
    cout << "│              РИБА                   │" << endl;
    cout << "├─────────────────────────────────────┤" << endl;

    cout << "│ Ім'я: " << (name.empty() ? "Без імені" : name);

    int spaces = 25 - (int)name.length();
    for (int i = 0; i < spaces; i++)
    {
      cout << " ";
    }
    cout << "│" << endl;

    cout << "│ Координати: ";
    coordinates.display();
    cout << "│ Рівень ситості: " << health << "%";

    cout << " [";
    int bars = health / 10;
    for (int i = 0; i < 10; i++)
    {
      if (i < bars)
      {
        cout << "█";
      }
      else
      {
        cout << "░";
      }
    }
    cout << "] │" << endl;

    cout << "│ Статус: " << getFishStatus() << endl;

    cout << "└─────────────────────────────────────┘" << endl;
  }

  string getFishStatus() const
    {
      if (health >= 80)
        return "Ситий і задоволений 😊";
      else if (health >= 60)
        return "Нормально харчується 🙂";
      else if (health >= 40)
        return "Трохи голодний 😐";
      else if (health >= 20)
        return "Голодний 😟";
      else
        return "Дуже голодний! 😰";
    }
};