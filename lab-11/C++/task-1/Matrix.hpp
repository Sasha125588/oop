#pragma once

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

template <typename T, unsigned row = 0, unsigned col = 0> 
class Matrix {
private:
  T **arr;

  void allocate() {
    arr = new T*[row];
    for (int r = 0; r < row; r++) {
      arr[r] = new T*[col]();
    }
  }

  void deallocate() {
    for (int r = 0; r < row; r++) {
      delete[] arr[r];
    }
    delete[] arr;
  }

  void ensureNotEmpty() const
  {
    if (row == 0 || col == 0)
      throw runtime_error("Matrix is empty");
  }

  void ensureValidIndex(int r, int c) const
  {
    if (r < 0 || r >= row || c < 0 || c >= col)
      throw out_of_range("Index out of bounds");
  }

public:
  Matrix() {
    allocate();
  }
  Matrix(T value) {
    allocate();
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        arr[r][c] = value;
      }
    }
  }
  Matrix(const Matrix &other) {
    allocate();
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        arr[r][c] = other.arr[r][c];
      }
    }
  }

  ~Matrix() { 
    deallocate();
  }

  int getLength(int dimension) const { 
    return dimension == 0 ? row : col; 
  }

  T getSum() const {
    T sum = 0;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        sum += arr[r][c];
      }
    }
    return sum;
  }

  bool findByValue(T value) const {
    ensureNotEmpty();

    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (arr[r][c] == value)
          return true;
      }
    }
    return false;
  }

  T findMin() const {
    ensureNotEmpty();

    T min = arr[0][0];
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (arr[r][c] < min)
          min = arr[r][c];
      }
    }
    return min;
  }

  T findMax() const {
    ensureNotEmpty();

    T max = arr[0][0];
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (arr[r][c] > max)
          max = arr[r][c];
      }
    }
    return max;
  }

  void print() const {
    cout << "Matrix [" << row << "x" << col << "]:" << endl;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        cout << setw(8) << arr[r][c] << " ";
      }
      cout << endl;
    }
  }

  T &operator()(int r, int c) {
    ensureNotEmpty();
    ensureValidIndex(r, c);
    
    return arr[r][c];
  }

  const T &operator()(int r, int c) const {
    ensureNotEmpty();
    ensureValidIndex(r, c);
    
    return arr[r][c];
  }

  Matrix operator+(const Matrix &other) const {
    if (row != other.getLength(0) || col != other.getLength(1))
      throw invalid_argument("Matrix dimensions must match");

    Matrix result;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        result.arr[r][c] = arr[r][c] + other.arr[r][c];
      }
    }
    return result;
  }

  Matrix operator+(T value) const {
    Matrix result;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        result.arr[r][c] = arr[r][c] + value;
      }
    }
    return result;
  }

  friend Matrix operator+(T value, const Matrix &m) {
    return m + value;
  }

  Matrix &operator+=(T value) {
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        arr[r][c] += value;
      }
    }
    return *this;
  }

  Matrix &operator=(const Matrix &other) {
    if (this != &other) {
      for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
          arr[r][c] = other.arr[r][c];
        }
      }
    }
    return *this;
  }

  bool operator==(const Matrix &other) const {
    if (row != other.getLength(0) || col != other.getLength(1))
      return false;

    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (arr[r][c] != other.arr[r][c])
          return false;
      }
    }
    return true;
  }

  bool operator!=(const Matrix &other) const {
    return !(*this == other);
  }

  friend ostream &operator<<(ostream &os, const Matrix &m) {
    os << "Matrix [" << row << "x" << col << "]:" << endl;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        os << setw(8) << m.arr[r][c] << " ";
      }
      os << endl;
    }
    return os;
  }

  friend istream &operator>>(istream &is, Matrix &m) {
    cout << "Enter " << row * col << " elements for Matrix [" << row << "x" << col << "]:" << endl;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        cout << "Element [" << r << "][" << c << "]: ";
        is >> m.arr[r][c];
      }
    }
    return is;
  }
};
