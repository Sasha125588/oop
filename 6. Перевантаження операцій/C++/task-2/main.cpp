#include "String.hpp"

void testStringOperators();

int main()
{
    testStringOperators();
    return 0;
}

void testStringOperators()
{
    cout << "=== Тестування операторів класу String ===" << endl;

    // Тест 1: Конструктори
    cout << "\n1. Тестування конструкторів:" << endl;
    String s1("Hello");
    String s2(s1);
    String s3("World");

    cout << "s1: " << s1 << endl;
    cout << "s2 (копія s1): " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // Тест 2: Операція + (конкатенація)
    cout << "\n2. Тестування операції + (конкатенація):" << endl;
    String s4 = s1 + s3;
    cout << "s1 + s3: " << s4 << endl;

    String s5 = s1 + " C++";
    cout << "s1 + \" C++\": " << s5 << endl;

    String s6 = s1 + " Programming";
    cout << "s1 + string(\" Programming\"): " << s6 << endl;

    // Тест 3: Операція * (перетин символів)
    cout << "\n3. Тестування операції * (перетин символів):" << endl;
    String s7("Microsoft");
    String s8("Windows");
    String s9 = s7 * s8;
    cout << "s7: " << s7 << endl;
    cout << "s8: " << s8 << endl;
    cout << "s7 * s8 (перетин): " << s9 << endl;

    // Тест 4: Операція / (різниця символів)
    cout << "\n4. Тестування операції / (різниця символів):" << endl;
    String s10 = s7 / s8;
    cout << "s7 / s8 (різниця): " << s10 << endl;

    // Тест 5: Оператори інкременту
    cout << "\n5. Тестування операторів інкременту:" << endl;
    String s11("Abcd");
    cout << "Початкове значення s11: " << s11 << endl;

    ++s11;
    cout << "Після ++s11: " << s11 << endl;

    String s12 = s11++;
    cout << "s12 = s11++: " << s12 << endl;
    cout << "s11 після s11++: " << s11 << endl;

    // Тест 6: Оператори порівняння
    cout << "\n6. Тестування операторів порівняння:" << endl;
    String s13("apple");
    String s14("banana");
    String s15("apple");

    cout << "s13: " << s13 << endl;
    cout << "s14: " << s14 << endl;
    cout << "s15: " << s15 << endl;

    cout << "s13 == s15: " << (s13 == s15 ? "true" : "false") << endl;
    cout << "s13 != s14: " << (s13 != s14 ? "true" : "false") << endl;
    cout << "s13 < s14: " << (s13 < s14 ? "true" : "false") << endl;
    cout << "s14 > s13: " << (s14 > s13 ? "true" : "false") << endl;
    cout << "s13 <= s15: " << (s13 <= s15 ? "true" : "false") << endl;
    cout << "s13 >= s15: " << (s13 >= s15 ? "true" : "false") << endl;

    // Тест 7: Оператор ! (реверс)
    cout << "\n7. Тестування оператора ! (реверс):" << endl;
    String s16("Windows");
    String s17 = !s16;
    cout << "s16: " << s16 << endl;
    cout << "!s16 (реверс): " << s17 << endl;

    // Тест 8: Оператор [] (індексація)
    cout << "\n8. Тестування оператора [] (індексація):" << endl;
    String s18("Hello");
    cout << "s18: " << s18 << endl;
    cout << "s18[0]: " << s18[0] << endl;
    cout << "s18[4]: " << s18[4] << endl;

    // Тест 9: Оператор () (підрядок)
    cout << "\n9. Тестування оператора () (підрядок):" << endl;
    String s19("My program");
    cout << "s19: " << s19 << endl;
    String s20 = s19(3);
    cout << "s19(3): " << s20 << endl;
    String s21 = s19(3, 4);
    cout << "s19(3, 4): " << s21 << endl;

    // Тест 10: Оператор присвоєння
    cout << "\n10. Тестування оператора присвоєння:" << endl;
    String s22("Original");
    String s23("New Value");
    cout << "s22 до присвоєння: " << s22 << endl;
    cout << "s23: " << s23 << endl;

    s22 = s23;
    cout << "s22 після присвоєння: " << s22 << endl;

    // Тест 11: Оператор перетворення до int
    cout << "\n11. Тестування оператора перетворення до int:" << endl;
    String s24("123");
    String s25("456");
    int num1 = s24;
    int num2 = s25;
    cout << "s24: " << s24 << endl;
    cout << "s24 як int: " << num1 << endl;
    cout << "s25: " << s25 << endl;
    cout << "s25 як int: " << num2 << endl;
    cout << "Сума: " << (num1 + num2) << endl;

    // Тест 12: Оператори вводу/виводу
    cout << "\n12. Тестування операторів вводу/виводу:" << endl;
    cout << "Введіть рядок: ";
    String s26("");
    cin >> s26;
    cout << "Ви ввели: " << s26 << endl;

    // Тест 13: Обробка помилок індексації
    cout << "\n13. Тестування обробки помилок індексації:" << endl;
    String s27("Test");
    cout << "s27: " << s27 << endl;

    try
    {
        cout << "s27[10]: " << s27[10] << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Помилка: " << e.what() << endl;
    }

    try
    {
        cout << "s27[-1]: " << s27[-1] << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Помилка: " << e.what() << endl;
    }

    cout << "\n=== Тестування завершено ===" << endl;
}
