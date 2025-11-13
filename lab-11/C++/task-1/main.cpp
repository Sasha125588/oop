#include <iostream>
#include <string>
#include "Matrix.hpp"

using namespace std;

void testMatrixTemplate();

int main() {
  testMatrixTemplate();

  return 0;
}

void testMatrixTemplate() {
    cout << "========================================" << endl;
    cout << "   Testing Matrix Template Class" << endl;
    cout << "========================================" << endl << endl;
  
    // ============ Testing with int type ============
    cout << ">>> Testing with int type <<<" << endl << endl;
    
    // Constructor with parameter
    Matrix<int, 2, 3> intMatrix1(5);
    cout << "Created Matrix<int, 2, 3> filled with 5:" << endl;
    intMatrix1.print();
    cout << endl;
  
    // Element access using operator()
    intMatrix1(0, 0) = 10;
    intMatrix1(0, 1) = 20;
    intMatrix1(1, 2) = 30;
    cout << "Modified some elements:" << endl;
    intMatrix1.print();
    cout << endl;
  
    // Test getSum
    cout << "Sum of all elements: " << intMatrix1.getSum() << endl << endl;
  
    // Test findMin and findMax
    cout << "Minimum element: " << intMatrix1.findMin() << endl;
    cout << "Maximum element: " << intMatrix1.findMax() << endl << endl;
  
    // Test findByValue
    cout << "Does matrix contain 20? " << (intMatrix1.findByValue(20) ? "Yes" : "No") << endl;
    cout << "Does matrix contain 100? " << (intMatrix1.findByValue(100) ? "Yes" : "No") << endl << endl;
  
    // Test matrix + matrix
    Matrix<int, 2, 3> intMatrix2(2);
    cout << "Second matrix filled with 2:" << endl;
    intMatrix2.print();
    cout << endl;
  
    Matrix<int, 2, 3> intMatrix3 = intMatrix1 + intMatrix2;
    cout << "Result of matrix1 + matrix2:" << endl;
    intMatrix3.print();
    cout << endl;
  
    // Test matrix + scalar
    Matrix<int, 2, 3> intMatrix4 = intMatrix1 + 10;
    cout << "Result of matrix1 + 10:" << endl;
    intMatrix4.print();
    cout << endl;
  
    // Test scalar + matrix
    Matrix<int, 2, 3> intMatrix5 = 3 + intMatrix2;
    cout << "Result of 3 + matrix2:" << endl;
    intMatrix5.print();
    cout << endl;
  
    // Test operator +=
    intMatrix1 += 5;
    cout << "Matrix1 after += 5:" << endl;
    intMatrix1.print();
    cout << endl;
  
    // Test equality operators
    Matrix<int, 2, 3> intMatrix6(15);
    intMatrix6(0, 0) = 15;
    intMatrix6(0, 1) = 25;
    intMatrix6(1, 2) = 35;
    
    cout << "Are matrix1 and matrix6 equal? " << (intMatrix1 == intMatrix6 ? "Yes" : "No") << endl;
    cout << "Are matrix1 and matrix6 different? " << (intMatrix1 != intMatrix6 ? "Yes" : "No") << endl << endl;
  
    // Test stream output operator
    cout << "Using << operator:" << endl;
    cout << intMatrix1;
    cout << endl;
  
    // ============ Testing with double type ============
    cout << ">>> Testing with double type <<<" << endl << endl;
    
    Matrix<double, 3, 2> doubleMatrix1(3.14);
    cout << "Created Matrix<double, 3, 2> filled with 3.14:" << endl;
    doubleMatrix1.print();
    cout << endl;
  
    doubleMatrix1(0, 0) = 1.5;
    doubleMatrix1(1, 1) = 2.7;
    doubleMatrix1(2, 0) = 9.8;
    cout << "Modified double matrix:" << endl;
    cout << doubleMatrix1;
    cout << endl;
  
    cout << "Sum: " << doubleMatrix1.getSum() << endl;
    cout << "Min: " << doubleMatrix1.findMin() << endl;
    cout << "Max: " << doubleMatrix1.findMax() << endl << endl;
  
    Matrix<double, 3, 2> doubleMatrix2 = doubleMatrix1 + 1.5;
    cout << "Double matrix + 1.5:" << endl;
    cout << doubleMatrix2;
    cout << endl;
  
    // ============ Testing with string type ============
    cout << ">>> Testing with string type <<<" << endl << endl;
    
    Matrix<string, 2, 2> stringMatrix1("hello");
    cout << "Created Matrix<string, 2, 2> filled with 'hello':" << endl;
    stringMatrix1.print();
    cout << endl;
  
    stringMatrix1(0, 0) = "C++";
    stringMatrix1(0, 1) = "is";
    stringMatrix1(1, 0) = "very";
    stringMatrix1(1, 1) = "cool";
    cout << "Modified string matrix:" << endl;
    cout << stringMatrix1;
    cout << endl;
    
    stringMatrix1.getSum();

    stringMatrix1 += string("Jdsajkkdskda");
    cout << "Modified string matrix:" << endl;
    cout << stringMatrix1;
    cout << endl;
  
    Matrix<string, 2, 2> stringMatrix2("!");
    Matrix<string, 2, 2> stringMatrix3 = stringMatrix1 + stringMatrix2;
    cout << "String matrix + matrix with '!':" << endl;
    cout << stringMatrix3;
    cout << endl;
  
    // Test string concatenation with scalar
    Matrix<string, 2, 2> stringMatrix4 = stringMatrix1 + "!";
    cout << "String matrix + '!':" << endl;
    cout << stringMatrix4;
    cout << endl;
  
    stringMatrix1 += "?";
    cout << "String matrix after += '?':" << endl;
    cout << stringMatrix1;
    cout << endl;
  
    cout << "Contains 'C++?': " << (stringMatrix1.findByValue("C++?") ? "Yes" : "No") << endl;
    cout << "Contains 'Python': " << (stringMatrix1.findByValue("Python") ? "Yes" : "No") << endl << endl;
  
    cout << "========================================" << endl;
    cout << "   All tests completed successfully!" << endl;
    cout << "========================================" << endl;
}