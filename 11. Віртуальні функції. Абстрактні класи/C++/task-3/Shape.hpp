#pragma once

class Shape {
private:
public:
  virtual ~Shape() {};
  virtual double area() const { return 0; }
  virtual double volume() const { return 0; }

  virtual void print() const = 0;
  virtual void printShapeName() const = 0;
};

// Spape shape;