#include <algorithm>
#include <iostream>
using namespace std;

enum Side { North, South, East, West };

class Room {
private:
  double width;
  double length;
  Side side;

public:
  Room(double width, double length, Side side)
      : width(width), length(length), side(side) {};
  Room(const Room &other)
      : width(other.width), length(other.length), side(other.side) {};

  double getWidth() const { return width; };
  void setWidth(double width) {
    this->width = max(0.0, width);
  };

  double getLength() const { return length; };
  void setLength(double length) {
    this->length = max(0.0, length);
  };

  Side getSide() const { return side; };
  void setSide(const Side& side) {
    this->side = side;
  };

  void print() const {
    cout << "Width: " << width << ", Length: " << length << ", Side: " << side
         << endl;
  };

  Room operator+(const Room &other) const {
    double newWidth = max(0.0, width + other.width);
    double newLength = max(0.0, length + other.length);

    return Room(newWidth, newLength, side);
  }

  Room operator+(int size) const {
    double newWidth = max(0.0, width + size);
    double newLength = max(0.0, length + size);

    return Room(newWidth, newLength, side);
  }

  Room operator-(int size) const {
    double newWidth = max(0.0, width - size);
    double newLength = max(0.0, length - size);

    return Room(newWidth, newLength, side);
  };

  Room operator*(int size) const {
    double newWidth = max(0.0, width * size);
    double newLength = max(0.0, length * size);

    return Room(newWidth, newLength, side);
  };

  Room &operator++() {
    ++width;
    ++length;
    return *this;
  }

  Room operator++(int) {
    Room temp = *this;
    ++(*this);
    return temp;
  }

  Room &operator--() {
    width = max(0.0, width - 1);
    length = max(0.0, length - 1);
    return *this;
  }

  Room operator--(int) {
    Room temp = *this;
    --(*this);
    return temp;
  }

  bool operator==(const Room& other) const {
    return width == other.width && length == other.length && side == other.side;
  }

  bool operator!=(const Room& other) const {
    return !(*this == other);
  }

  bool operator<(const Room& other) const {
    return width * length < other.width * other.length;
  }

  Room& operator+=(int size) {
    width = max(0.0, width + size);
    length = max(0.0, length + size);
    return *this;
  }

  Room& operator*=(int size) {
    width = max(0.0, width * size);
    length = max(0.0, length * size);
    return *this;
  }

  operator double() const {
    return width * length;
  }

  Room& operator=(const Room& other) {
    width = other.width;
    length = other.length;
    side = other.side;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream &out, const Room& room) {
    out << "Width: " << room.width << ", Length: " << room.length << ", Side(0-3): " << room.side << endl;
    return out;
  }

  friend std::istream& operator>>(std::istream &in, Room& room) {
    int sideInt;
    in >> room.width >> room.length >> sideInt;
    room.side = Side(sideInt);
    return in;
  }
};