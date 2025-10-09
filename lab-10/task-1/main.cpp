#include <iostream>
#include <cmath>
#include <string>

using namespace std;


double processArea(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw string("Сторони мають бути додатні");
    }
    
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw string("Сторони не утворюють трикутник");
    }
    
    double p = (a + b + c) / 2.0;  
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    
    return area;
}

int main()
{
    double a, b, c;
    
    cout << "Програма обчислення площі трикутника за трьома сторонами" << endl;
    cout << "Введіть 0 для першої сторони, щоб вийти з програми" << endl << endl;
    
    while (true) {
        try {
            cout << "Введіть три сторони трикутника (a b c): ";
            cin >> a >> b >> c;
            
            double area = processArea(a, b, c);
            cout << "Площа трикутника: " << area << endl << endl;
            
        } catch (const string& ex) {
            cout << "[ПОМИЛКА]: " << ex << endl << endl;
        }
    }
    
    return 0;
}
