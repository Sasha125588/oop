#pragma once

#include <cmath>
#include <iostream>

using namespace std;

class Point {
private:
  int x;
  int y;
  char name = '@';

  static char lastNameOfPoint;
  static int count;

  void assignName()
  {
    lastNameOfPoint++;
    if (lastNameOfPoint > 'Z')
      lastNameOfPoint = 'A';
    name = lastNameOfPoint;
  }

public:
  Point(int x, int y) {
    this->x = x;
    this->y = y;
    assignName();
    count++;
  };
  Point(const Point &other) {
    this->x = other.x;
    this->y = other.y;
    assignName(); // в кожної точки має бути унікальне імʼя чи при копії імʼя теж копіюється?
    count++;
  };
  Point() {
    this->x = 0;
    this->y = 0;
    assignName();
    count++;
  };

  ~Point() { count--; };

  int getX() const { return x; }
  void setX(int x) { this->x = x; };

  int getY() const { return y; }
  void setY(int y) { this->y = y; };

  char getName() const { return name; }

  inline static int getCount() { return count; }

  static void resetCount() {
    count = 0;
    lastNameOfPoint = '@';
  }

  double distanceToOrigin() const { return sqrt(x * x + y * y); }

  Point &add(const Point &other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  Point &subtract(const Point &other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
  }

  static bool equals(const Point &p1, const Point &p2) {
    return p1.x == p2.x && p1.y == p2.y;
  }

  static int compareByDistance(const Point &p1, const Point &p2) {
    double dist1 = p1.distanceToOrigin();
    double dist2 = p2.distanceToOrigin();

    if (dist1 < dist2)
      return -1; // p1 ближче
    if (dist1 > dist2)
      return 1; // p1 далі
    return 0;
  }

  static Point findClosestToOrigin(Point *points, int size) {
    if (size <= 0)
      return Point();

    int closestIndex = 0;
    for (int i = 1; i < size; i++) {
      if (points[i].distanceToOrigin() <
          points[closestIndex].distanceToOrigin()) {
        closestIndex = i;
      }
    }
    return points[closestIndex];
  }

  void printPoint() const {
    cout << "Точка " << ": " << this->name << "(" << this->x << ", "
         << this->y << ")" << endl;
  };

  void display() const {
    cout << "Точка " << name << ": (" << x << ", " << y << ")" << endl;
  }

  static void displayAll(Point *points, int size) {
    for (int i = 0; i < size; i++) {
      points[i].display();
    }
  }

  Point operator+(const Point &other) const {
    return Point(x + other.x, y + other.y);
  }

  Point operator-(const Point &other) const {
    return Point(x - other.x, y - other.y);
  }
};
