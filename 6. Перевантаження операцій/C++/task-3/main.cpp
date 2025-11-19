#include "Vector.hpp"

void testBasicOperations();
void testAssignmentTests();

int main() {
    // testAssignmentTests();
    testBasicOperations();
    return 0;
}

// Це тести які в лабі є
void testAssignmentTests() {
    cout << "\n=== ТЕСТИ З ЗАВДАННЯ ===" << endl;
    
    Vector<int> v1(2); // фактичний розмір = 2, елементи нулі
    v1.pushBack(10);
    v1.pushBack(20);
    cout << "The size of v1 is " << v1.getSize() << endl; // 4
    cout << "The capacity of v1 is " << v1.getCapacity() << endl; // >=4
    v1.print(); // 0 0 10 20
    
    if (!v1.empty()) // якщо не пусто
        v1.popBack(); // вилучили останній
    v1.print(); // 0 0 10
    cout << "The size of v1 is " << v1.getSize() << endl; // 3

    v1.printInfo();
    
    cout << "Reserve new capacity(20)" << endl;
    v1.reserve(20); // capacity = 20, size = яке було(3)
    v1.printInfo();
    v1.front() = 1234; // перший елемент замінили на 1234
    v1.clear();
    cout << "The size of v1 after clearing is " << v1.getSize() << endl; // 0
    
    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3); // v1: 1 2 3
    
    Vector<int> v2(4, -1); // v2 : -1 -1 -1 -1
    v2[1] = 20; // v2 : -1 20 -1 -1
    
    Vector<int> v3 = v1 + v2; // v3: 1 2 3 -1 20 -1 -1
    cout << "v3 is ";
    v3.print(); // 
    
    v3 = v1 * 5; // v3: 5 10 15
    cout << "v3 is ";
    v3.print(); // 
    
    v2 *= 10; // v2 : -10 200 -10 -10
    cout << "v2 *= 10: ";
    v2.print();
    
    v2 += Vector<int>(3, 5); // v2 : -10 200 -10 -10 5 5 5
    cout << "v2 += Vector(3, 5): ";
    v2.print();
}

void testBasicOperations() {
    cout << "\n=== ТЕСТИ ОСНОВНИХ ОПЕРАЦІЙ ===" << endl;
    
    // Тест конструкторів
    cout << "\n1. Тест конструкторів:" << endl;
    Vector<int> v1(3);
    Vector<int> v2(4, -1);
    Vector<int> v3; // порожній вектор
    
    cout << "v1(3): size=" << v1.getSize() << ", capacity=" << v1.getCapacity() << endl;
    cout << "v2(4, -1): size=" << v2.getSize() << ", capacity=" << v2.getCapacity() << endl;
    cout << "v3(): size=" << v3.getSize() << ", capacity=" << v3.getCapacity() << endl;
    
    // Тест pushBack
    cout << "\n2. Тест pushBack:" << endl;
    v1.pushBack(10);
    v1.pushBack(20);
    v1.pushBack(30);
    cout << "Після pushBack(10,20,30): ";
    v1.print();
    
    // Тест операторів
    cout << "\n3. Тест операторів:" << endl;
    Vector<int> v4 = v1 * 2; // множення на число
    cout << "v1 * 2: ";
    v4.print();
    
    Vector<int> v5 = v1 + v2; // додавання векторів
    cout << "v1 + v2: ";
    v5.print();
    
    Vector<int> v6 = !v1; // реверс
    cout << "!v1 (реверс): ";
    v6.print();
    
    // Тест префіксного ++
    cout << "\n4. Тест префіксного ++:" << endl;
    cout << "До ++v1: ";
    v1.print();
    ++v1;
    cout << "Після ++v1: ";
    v1.print();
    
    // Тест постфіксного ++
    cout << "\n5. Тест постфіксного ++:" << endl;
    Vector<int> v7 = v1++;
    cout << "v1++ повернув: ";
    v7.print();
    cout << "v1 після v1++: ";
    v1.print();
    
    // Тест операторів присвоєння
    cout << "\n6. Тест операторів присвоєння:" << endl;
    Vector<int> v8 = v1;
    v8 *= 3;
    cout << "v8 *= 3: ";
    v8.print();
    
    v8 += v2;
    cout << "v8 += v2: ";
    v8.print();
    
    // Тест перетворення до int
    cout << "\n7. Тест перетворення до int:" << endl;
    int sum = v1;
    cout << "Сума елементів v1: " << sum << endl;
    
    // Тест front() та back()
    cout << "\n8. Тест front() та back():" << endl;
    cout << "v1.front() = " << v1.front() << endl;
    cout << "v1.back() = " << v1.back() << endl;
    
    v1.front() = 999;
    v1.back() = 888;
    cout << "Після зміни front() та back(): ";
    v1.print();
}
