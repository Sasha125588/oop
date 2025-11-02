#include <exception>
#include <iostream>
#include <cmath>

#include "./WrongSideError.hpp"
#include "./WrongTrianError.hpp"

using namespace std;

double processArea(double a, double b, double c);

int main()
{
    double a, b, c;
        
    while (true) {
        try {
            cout << "Введіть три сторони трикутника (a b c): ";
            cin >> a >> b >> c;
            
            double area = processArea(a, b, c);
            cout << "Площа трикутника: " << area << endl << endl;
            
        } catch (const WrongSideError& ex) {
            cout << "[ПОМИЛКА - " << typeid(ex).name() << "]:" << ex.getErrMsg() << endl << endl;
        } catch (const WrongTrianError& ex) {
            cout << "[ПОМИЛКА - " << typeid(ex).name() << "]:" << ex.getErrMsg() << endl << endl;
        } catch (exception ex) {}
    }
    
    return 0;
}

double processArea(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw WrongSideError("Сторони мають бути додатні");
    }
    
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw WrongTrianError("Сторони не утворюють трикутник");
    }
    
    double p = (a + b + c) / 2.0;  
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    
    return area;
}
