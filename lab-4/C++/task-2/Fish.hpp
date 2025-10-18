#pragma once

#include "../task-1/Point.hpp"
#include <iostream>
#include <string>

using namespace std;

class Fish
{
private:
  string name = "";
  Point coordinates = Point(0, 0);
  short health = 100;

  inline bool isValidPosition(int x, int y) const
  {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
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

public:
  static char ocean[10][10];
  static int countOfLiveFish;

  Fish() : health(100) { countOfLiveFish++; }
  Fish(string name)
  {
    this->name = name;
    countOfLiveFish++;
  }

  Fish(short health)
  {
    this->health = health;
    countOfLiveFish++;
  }

  Fish(const Point &coordinates)
  {
    this->coordinates = coordinates;
    countOfLiveFish++;
  }

  Fish(string name, short health)
  {
    this->name = name;
    this->health = health;
    countOfLiveFish++;
  }

  Fish(string name, short health, Point coordinates)
  {
    this->name = name;
    this->health = health;
    this->coordinates = coordinates;
    countOfLiveFish++;
  }

  ~Fish() { countOfLiveFish--; }

  const string &getName() const { return name; }
  void setName(string name) { this->name = name; }

  const Point &getCoordinates() const { return coordinates; }
  void setCoordinates(const Point &coords) { coordinates = coords; }

  short getHealth() const { return health; }
  void setHealth(short newHealth)
  {
    if (newHealth >= 0 && newHealth <= 100)
    {
      health = newHealth;
    }
  }

  void feed(int foodAmount)
  {
    health += foodAmount;
    if (health > 100)
      health = 100;
  }

  void decreaseHunger(int amount = 5)
  {
    health -= amount;
    if (health < 0)
      health = 0;
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
    for (int x = 0; x < 10; x++)
    {
      cout << x << " ";
    }
    cout << "│" << endl;

    for (int y = 0; y < 10; y++)
    {
      cout << "│ " << y << " ";
      for (int x = 0; x < 10; x++)
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
    for (int y = 0; y < 10; y++)
    {
      for (int x = 0; x < 10; x++)
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
      int x = rand() % 10;
      int y = rand() % 10;

      if (ocean[y][x] == '~')
      {
        ocean[y][x] = '*';
        placedSeaweed++;
      }
    }
  }

  static void spawnSeaweed()
  {
    int x = rand() % 10;
    int y = rand() % 10;

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

    cout << "│ Статус: ";
    if (health >= 80)
    {
      cout << "Ситий та здоровий        │" << endl;
    }
    else if (health >= 60)
    {
      cout << "Добре нагодований        │" << endl;
    }
    else if (health >= 40)
    {
      cout << "Потребує їжі             │" << endl;
    }
    else if (health >= 20)
    {
      cout << "Голодний                 │" << endl;
    }
    else
    {
      cout << "Критично голодний!       │" << endl;
    }

    cout << "└─────────────────────────────────────┘" << endl;
  }
};