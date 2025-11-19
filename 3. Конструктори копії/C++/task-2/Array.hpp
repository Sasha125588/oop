#pragma once

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Array
{
private:
  T *arr;
  int size;
  int capacity;

  void alloc(int newCapacity)
  {
    capacity = newCapacity;
    T *newArr = new T[capacity];

    for (int i = 0; i < size; i++)
    {
      newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
  }

  int getNewCapacity()
  {
    if (capacity == 0)
      return 1;

    if (capacity < 256)
      return capacity * 2;

    return (capacity * 1.25 + 3 * 256 / 4);
  }

  void ensureNotEmpty() const
  {
    if (size == 0)
      throw runtime_error("Array is empty");
  }

  void ensureValidIndex(int index) const
  {
    if (index < 0 || index >= size)
      throw invalid_argument("Index out of bounds");
  }

public:
  Array()
  {
    size = 10;
    capacity = size;
    arr = new T[capacity]{0};
  }
  Array(int size)
  {
    this->size = size;
    capacity = size;
    arr = new T[capacity]{0};
  }
  Array(int size, T value)
  {
    this->size = size;
    capacity = size;
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
    {
      arr[i] = value;
    }
  }
  Array(const Array &other)
  {
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
    {
      arr[i] = other.arr[i];
    }
  }

  ~Array() { delete[] arr; }

  inline int getSize() const { return size; }
  inline int getCapacity() const { return capacity; }

  void add(T value)
  {
    if (size >= capacity)
    {
      alloc(getNewCapacity());
    }
    arr[size] = value;
    size++;
  }

  void removeByIndex(int index)
  {
    ensureNotEmpty();
    ensureValidIndex(index);

    for (int i = index; i < size - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    size--;

    if (size < capacity / 2 && capacity > 10)
    {
      alloc(capacity / 2);
    }
  }

  bool removeByValue(T value)
  {
    for (int i = 0; i < size; i++)
    {
      if (arr[i] == value)
      {
        removeByIndex(i);
        return true;
      }
    }
    return false;
  }

  void sort(bool order)
  {
    if (order)
    {
      std::sort(arr, arr + size, std::less<T>());
    }
    else
    {
      std::sort(arr, arr + size, std::greater<T>());
    }
  }

  inline T findMin() const
  {
    ensureNotEmpty();

    return *min_element(arr, arr + size);
  }

  inline T findMax() const
  {
    ensureNotEmpty();

    return *max_element(arr, arr + size);
  }

  inline int indexOf(T value) const
  {
    int index = find(arr, arr + size, value) - arr;
    return index >= size ? -1 : index;
  }

  void fill(T value)
  {
    for (int i = 0; i < size; i++)
    {
      arr[i] = value;
    }
  }

  void fillRandomValue()
  {
    for (int i = 0; i < size; i++)
    {
      arr[i] = (rand() % 100) + 1;
    }
  }

  void print()
  {
    cout << "┌─────────────────────────────────────┐" << endl;
    cout << "│              Array [" << size << "]              │" << endl;
    cout << "├─────────────────────────────────────┤" << endl;

    if (size == 0)
    {
      cout << "│              (empty)              │" << endl;
    }
    else
    {
      for (int i = 0; i < size; i++)
      {
        cout << "│ [" << i << "] = " << arr[i];

        int spaces = 8 - to_string(arr[i]).length();
        for (int j = 0; j < spaces; j++)
        {
          cout << " ";
        }
        cout << "│" << endl;
      }
    }

    cout << "└─────────────────────────────────────┘" << endl;
  }

  void printInfo()
  {
    cout << "┌─────────────────────────────────────┐" << endl;
    cout << "│            Array Info               │" << endl;
    cout << "├─────────────────────────────────────┤" << endl;
    cout << "│ Pointer: " << arr << " │" << endl;
    cout << "│ Size: " << size << "                           │" << endl;
    cout << "│ Capacity: " << capacity << "                       │" << endl;
    cout << "└─────────────────────────────────────┘" << endl;
  }

  inline T &operator[](int index)
  {
    ensureNotEmpty();
    ensureValidIndex(index);

    return arr[index];
  }

  inline const T &operator[](int index) const
  {
    ensureNotEmpty();
    ensureValidIndex(index);

    return arr[index];
  }
};