#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Parrot.hpp"
#include "Hamster.hpp"
#include <vector>

using namespace std;

void testVirtualMethods();
void printSeparator();

int main()
{
    testVirtualMethods();
    
    return 0;
}

void printSeparator() {
    cout << string(60, '=') << endl;
}

void testVirtualMethods() {
    cout << "\n";
    printSeparator();
    cout << "           ТЕСТ ВІРТУАЛЬНИХ МЕТОДІВ ТВАРИНОК" << endl;
    printSeparator();
    cout << "\n";

    vector<Animal*> animals = {
        new Dog("Rex", 3, "German Shepherd", "Brown"),
        new Cat("Kiskiskin", 2, "Street Cat", "Black & White"),
        new Parrot("Kesha", 5, "Green", true),
        new Hamster("Fluffy", 1, "Golden", "Long"),
        new Dog("Buddy", 5, "Golden Retriever", "Golden"),
        new Cat("Murka", 4, "Persian", "Gray"),
        new Parrot("Rio", 2, "Blue", false),
        new Hamster("Tiny", 1, "White", "Short")
    };

    cout << "Всього тваринок у масиві: " << animals.size() << "\n" << endl;

    int count = 1;
    for (auto animal : animals) {
        cout << "🐾 Тваринка #" << count << ":" << endl;
        cout << "   Тип: ";
        animal->type();
        cout << "   Звук: ";
        animal->sound();
        cout << "   Інформація: ";
        animal->show();
        cout << endl;
        count++;
    }

    printSeparator();
    cout << "           ТЕСТ ЗАВЕРШЕНО УСПІШНО!" << endl;
    printSeparator();
    cout << "\n";

    for (auto animal : animals) {
        delete animal;
    }
}
