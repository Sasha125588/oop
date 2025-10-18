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
  void setWidth(double width) { this->width = width; };

  double getLength() const { return length; };
  void setLength(double length) { this->length = length; };

  Side getSide() const { return side; };
  void setSide(Side side) { this->side = side; };

  void print() const {
    cout << "Width: " << width << ", Length: " << length << ", Side: " << side
         << endl;
  };

  Room operator+(const Room &other) const {
    if (width + other.width > 0 && length + other.length > 0) {
      return Room(width + other.width, length + other.length, side);
    }
    return *this;
  }

  Room operator+(int size) const {
    if (width + size > 0 && length + size > 0) {
      return Room(width + size, length + size, side);
    }
    return *this;
  }

  Room operator-(int size) const {
    if (width - size > 0 && length - size > 0) {
      return Room(width - size, length - size, side);
    }
    return *this;
  };

  Room operator*(int size) const {
    if (width * size > 0 && length * size > 0) {
      return Room(width * size, length * size, side);
    }
    return *this;
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
    --width;
    --length;
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
    width += size;
    length += size;
    return *this;
  }

  Room& operator*=(int size) {
    width *= size;
    length *= size;
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

  friend std::ostream& operator<< (std::ostream &out, const Room& room) {
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