#include <iostream>
#include "Room.hpp"
using namespace std;

void testRoomOperators(); 

int main()
{
    testRoomOperators();
    return 0;
}

void testRoomOperators() {
    cout << "=== Тестування операторів класу Room ===" << endl;
    
    // Тест 1: Базові операції
    cout << "\n1. Тестування базових операцій:" << endl;
    Room room1(5.0, 4.0, North);
    Room room2(3.0, 2.0, South);
    
    cout << "room1: " << room1 << endl;
    cout << "room2: " << room2 << endl;
    
    Room room3 = room1 + room2;
    cout << "room1 + room2: " << room3 << endl;
    
    Room room4 = room1 + 2;
    cout << "room1 + 2: " << room4 << endl;
    
    Room room5 = room1 - 1;
    cout << "room1 - 1: " << room5 << endl;
    
    Room room6 = room1 * 2;
    cout << "room1 * 2: " << room6 << endl;
    
    // Тест 2: Оператори інкременту/декременту
    cout << "\n2. Тестування операторів інкременту/декременту:" << endl;
    Room room7(3.0, 3.0, East);
    cout << "Початкове значення: " << room7 << endl;
    
    ++room7;
    cout << "Після ++room7: " << room7 << endl;
    
    room7++;
    cout << "Після room7++: " << room7 << endl;
    
    --room7;
    cout << "Після --room7: " << room7 << endl;
    
    room7--;
    cout << "Після room7--: " << room7 << endl;
    
    // Тест 3: Оператори порівняння
    cout << "\n3. Тестування операторів порівняння:" << endl;
    Room room8(4.0, 5.0, West);
    Room room9(4.0, 5.0, West);
    Room room10(2.0, 3.0, North);
    
    cout << "room8: " << room8 << endl;
    cout << "room9: " << room9 << endl;
    cout << "room10: " << room10 << endl;
    
    cout << "room8 == room9: " << (room8 == room9 ? "true" : "false") << endl;
    cout << "room8 != room10: " << (room8 != room10 ? "true" : "false") << endl;
    cout << "room10 < room8: " << (room10 < room8 ? "true" : "false") << endl;
    
    // Тест 4: Оператори присвоєння
    cout << "\n4. Тестування операторів присвоєння:" << endl;
    Room room11(2.0, 3.0, South);
    cout << "Початкове значення: " << room11 << endl;
    
    room11 += 2;
    cout << "Після room11 += 2: " << room11 << endl;
    
    room11 *= 2;
    cout << "Після room11 *= 2: " << room11 << endl;
    
    // Тест 5: Оператор перетворення в double (площа)
    cout << "\n5. Тестування оператора перетворення в double:" << endl;
    Room room12(6.0, 4.0, East);
    cout << "room12: " << room12 << endl;
    
    double area1 = room12; // Неявне перетворення
    cout << "Площа room12 (неявне перетворення): " << area1 << endl;
    
    double area2 = double(room12); // Явне перетворення
    cout << "Площа room12 (явне перетворення): " << area2 << endl;
    
    // Тест 6: Оператор присвоєння =
    cout << "\n6. Тестування оператора присвоєння =:" << endl;
    Room room13(1.0, 1.0, North);
    Room room14(7.0, 8.0, West);
    
    cout << "room13 до присвоєння: " << room13 << endl;
    cout << "room14: " << room14 << endl;
    
    room13 = room14;
    cout << "room13 після присвоєння: " << room13 << endl;
    
    // Тест 7: Оператори вводу/виводу
    cout << "\n7. Тестування операторів вводу/виводу:" << endl;
    cout << "Введіть параметри кімнати (ширина довжина сторона): ";
    Room room15(0, 0, North);
    cin >> room15;
    cout << "Введена кімната: " << room15 << endl;
    
    cout << "\n=== Тестування завершено ===" << endl;
}