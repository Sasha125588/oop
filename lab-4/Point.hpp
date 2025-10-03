#include <cmath>
#include <iostream>

using namespace std;

constexpr char names[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
};

class Point {
private:
  int x;
  int y;
  char name;
  static char lastNameOfPoint;
  static int count;

public:
  Point(int x, int y) {
    this->x = x;
    this->y = y;
    this->name = names[count];
    lastNameOfPoint = this->name;
    count++;
  };
  Point(const Point &p) {
    this->x = p.x;
    this->y = p.y;
    this->name = names[count];
    lastNameOfPoint = this->name;
    count++;
  };
  Point() {
    this->x = 0;
    this->y = 0;
    this->name = names[count];
    lastNameOfPoint = this->name;
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
  }

  double distanceToOrigin() const { return sqrt(x * x + y * y); }

  Point& add(const Point &other)  {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  Point& subtract(const Point &other) {
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
     
     if (dist1 < dist2) return -1;  // p1 ближче (різниця від'ємна)
     if (dist1 > dist2) return 1;   // p1 далі (різниця додатна)
     return 0;                      // рівні відстані
   }

    static Point findClosestToOrigin(Point* points, int size) {
        if (size <= 0) return Point();
        
        int closestIndex = 0;
        for (int i = 1; i < size; i++) {
            if (points[i].distanceToOrigin() < points[closestIndex].distanceToOrigin()) {
                closestIndex = i;
            }
        }
        return points[closestIndex];
   }


  void printPoint() const {
    cout << "Point " << count << ": " << this->name << "(" << this->x << ", "
         << this->y << ")" << endl;
  };

  void display() const {
    cout << "Точка " << name << ": (" << x << ", " << y << ")" << endl;
  }

  void displayAll(Point* points, int size) {
    for (int i = 0; i < size; i++) {
        points[i].display();
    }
  }

  Point& operator+(const Point &other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  Point& operator-(const Point &other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
  }
};
