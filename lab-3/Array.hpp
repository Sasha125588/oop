#pragma once 

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Array {
    private:
    T* arr;
    int size;
    int capacity;

    public:
    Array() {
        (*this).size = 0;
        capacity = 10;
        arr = new T[capacity]{0};
    }
    Array(int size) {
        this->size = 0;
        capacity = size;
        arr = new T[capacity]{0};
    }
    Array(int size, T value) {
        this->size = size;
        capacity = size;
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }
    Array(const Array& other) {
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~Array() {
        delete[] arr;
    }

    void add(T value) {
        if(size >= capacity) {
            capacity *= 2;
            T* newArr = new T[capacity];

            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }

            newArr[size] = value;
            delete[] arr;
            
            arr = newArr;
        } else {
            arr[size] = value;
        }
        size++;
    }
    
    void removeByIndex(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        
        
        if (size < capacity / 2 && capacity > 10) {
            capacity /= 2;
            T* newArr = new T[capacity];
            
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            
            delete[] arr;
            arr = newArr;
        }
    }
    
    bool removeByValue(T value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                removeByIndex(i);
                return true;
            }
        }
        return false; 
    }

    void sort(bool order) {
        if (order) {
            std::sort(arr, arr + size, std::less<T>());
        } else {
            std::sort(arr, arr + size, std::greater<T>());
        }
    }

    T findMin() {
        return *min_element(arr, arr + size);
    }

    T findMax() {
        return *max_element(arr, arr + size);;
    }

    int indexOf(T value) {
        int index = find(arr, arr + size, value) - arr;
        return index >= size ? -1 : index;
    }

    void fill(T value) {
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }

    void fillRandomValue() {
        for (int i = 0; i < size; i++) {
            arr[i] = (rand() % 100) + 1;
        }
    }

    void print() {
        cout << "┌─────────────────────────────────────┐" << endl;
        cout << "│              Array [" << size << "]              │" << endl;
        cout << "├─────────────────────────────────────┤" << endl;
        
        for (int i = 0; i < size; i++) {
            cout << "│ [" << i << "] = " << arr[i];
            // Добавляем пробелы для выравнивания
            int spaces = 8 - to_string(arr[i]).length();
            for (int j = 0; j < spaces; j++) {
                cout << " ";
            }
            cout << "│" << endl;
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

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    
    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }
};