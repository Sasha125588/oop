#pragma once

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <stdexcept>

using namespace std;

template <typename T> class Vector {
private:
  T *arr;
  int size;
  int capacity;

  void alloc() {
    capacity *= capacity < 256 ? 2 : 1.25 + 3.0 * 256.0 / 4.0;
    T *newArr = new T[capacity];

    for (int i = 0; i < size; i++) {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
  }

public:
  Vector() {
    size = 10;
    capacity = 10;
    arr = new T[capacity]{0};
  }
  Vector(int size) {
    this->size = size;
    capacity = size;
    arr = new T[capacity]{0};
  }
  Vector(int size, T value) {
    this->size = size;
    capacity = size;
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
      arr[i] = value;
    }
  }
  Vector(const Vector &other) {
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
      arr[i] = other.arr[i];
    }
  }

  ~Vector() { delete[] arr; }

  int getSize() const { return size; }

  int getCapacity() const { return capacity; }

  void reserve(int newCapacity) {
    if (newCapacity < capacity) {
      cout << "Invalid capacity" << endl;
      return;
    }

    T *newArr = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
  }

  bool empty() const { return size == 0; }

  T getValue(int index) const { return arr[index]; }

  void setValue(int index, int value) { arr[index] = value; }

  T &front() {
    int static errorFront = 0;
    if (empty())
      return errorFront;

    return arr[0];
  }

  T &back() {
    int static errorFront = 0;
    if (empty())
      return errorFront;

    return arr[size - 1];
  }

  void pushBack(T value) {
    if (size >= capacity) {
      alloc();
    }
    arr[size] = value;
    size++;
  }

  void insert(T value, int index) {
    if (index < 0 || index > size) {
      throw out_of_range("Index out of bounds");
      return;
    }

    if (size >= capacity) {
      alloc();
    }
    for (int i = size; i > index; i--) {
      swap(arr[i], arr[i - 1]);
    }
    arr[index] = value;
    size++;
  }

  void popBack() { removeByIndex(size - 1); }

  void removeByIndex(int index) {
    if (index < 0 || index > size) {
      throw out_of_range("Index out of bounds");
    }
    if (size == 0) {
      throw out_of_range("Array is empty");
    }

    for (int i = index; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }
    size--;

    if (size < capacity / 2 && capacity > 10) {
      capacity /= 2;
      T *newArr = new T[capacity];

      for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
      }

      delete[] arr;
      arr = newArr;
    }
  }

  void resize(int newSize, T value = 0) {
    size = newSize;
    if (size >= capacity) {
      alloc();
    }

    for (int i = 0; i < size; i++) {
      arr[i] = value;
    }
  }

  void clear() {
    delete[] arr;
    arr = new T[capacity];
    size = 0;
  }

  void print() {
    cout << "┌─────────────────────────────────────┐" << endl;
    cout << "│              Array [" << size << "]              │" << endl;
    cout << "├─────────────────────────────────────┤" << endl;

    if (size == 0) {
      cout << "│              (empty)              │" << endl;
    } else {
      for (int i = 0; i < size; i++) {
        cout << "│ [" << i << "] = " << arr[i];

        int spaces = 8 - to_string(arr[i]).length();
        for (int j = 0; j < spaces; j++) {
          cout << " ";
        }
        cout << "│" << endl;
      }
    }

    cout << "└─────────────────────────────────────┘" << endl;
  }

  void printInfo() {
    cout << "┌─────────────────────────────────────┐" << endl;
    cout << "│            Array Info               │" << endl;
    cout << "├─────────────────────────────────────┤" << endl;
    cout << "│ Pointer: " << arr << " │" << endl;
    cout << "│ Size: " << size << "                           │" << endl;
    cout << "│ Capacity: " << capacity << "                       │" << endl;
    cout << "└─────────────────────────────────────┘" << endl;
  }

  Vector<T> operator*(T value) const {
    Vector<T> newVector = *this;

    for (int i = 0; i < size; i++) {
      newVector[i] *= value;
    }

    return newVector;
  }

  Vector<T> operator+(const Vector &other) const {
    Vector<T> newVector = *this;

    for (int i = 0; i < other.size; i++) {
      newVector.pushBack(other.arr[i]);
    }

    return newVector;
  }

  Vector<T>& operator++() {
    for (int i = 0; i < size; i++) {
      ++arr[i];
  }
    return *this;
  }

  Vector<T> operator++(int) {
    Vector<T> temp = *this;
    ++(*this);
    return temp;
  }

  bool operator==(const Vector &other) const {
    if (size != other.size || capacity != other.capacity)
      return false;

    for (int i = 0; i < size; i++) {
      if (arr[i] != other.arr[i])
        return false;
    }
    return true;
  }

  bool operator!=(const Vector &other) const {
    if (size != other.size || capacity != other.capacity)
      return true;

    for (int i = 0; i < size; i++) {
      if (arr[i] != other.arr[i])
        return true;
    }
    return false;
  }

  Vector<T> operator!() const {
    Vector<T> reversed = *this;
    int l = 0, r = size -1;

    while (l < r) {
      swap(reversed[l], reversed[r]);
      l++;
      r--;
    }

    return reversed;
  }

  T &operator[](int index) {
    if (size == 0) {
      throw out_of_range("Array is empty");
    }
    if (index < 0 || index >= size) {
      throw out_of_range("Index out of bounds");
    }
    return arr[index];
  }

  const T &operator[](int index) const {
    if (size == 0) {
      throw out_of_range("Array is empty");
    }
    if (index < 0 || index >= size) {
      throw out_of_range("Index out of bounds");
    }
    return arr[index];
  }

  Vector<T> &operator=(const Vector<T> &other) {
    if (this != &other) {
      delete[] arr;
      arr = nullptr;
      size = other.size;
      capacity = other.capacity;
      arr = new T[capacity];
      for (int i = 0; i < size; i++) {
          arr[i] = other.arr[i];
      }
      return *this;
  }
  }

  Vector<T> &operator+=(const Vector<T> &other) {
    for (int i = 0; i < other.size; i++) {
        pushBack(other.getValue(i));
    }
    return *this;
}

  Vector<T> &operator*=(T value) {
    for (int i = 0; i < size; i++) {
      arr[i] *= value;
  }
    return *this;
  }

  operator int() const {
    return accumulate(arr, arr + size, 0);
  }
};