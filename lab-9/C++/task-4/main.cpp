#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Parrot.hpp"
#include "Hamster.hpp"

using namespace std;

void printSeparator();
void testAbstractClass();

int main()
{
    testAbstractClass();
    
    return 0;
}

void printSeparator() {
    cout << string(60, '=') << endl;
}

void testAbstractClass() {
    cout << "\n";
    printSeparator();
    cout << "        ТЕСТ АБСТРАКТНОГО КЛАСУ ANIMAL" << endl;
    printSeparator();
    cout << "\n";

    // ВАЖЛИВО: Неможливо створити об'єкт абстрактного класу!
    // Наступний рядок викличе помилку компіляції:
    // Animal animal("Generic", 5);  // ERROR: cannot declare variable 'animal' to be of abstract type 'Animal'
    
    cout << "ℹ️  Animal є абстрактним класом з чисто віртуальними функціями:" << endl;
    cout << "   - virtual void sound() const = 0;" << endl;
    cout << "   - virtual void type() const = 0;" << endl;
    cout << "\n⚠️  Неможливо створити екземпляр Animal напряму!\n" << endl;
    
    printSeparator();
    cout << "   СТВОРЕННЯ ТВАРИН ЧЕРЕЗ ВКАЗІВНИКИ НА БАЗОВИЙ КЛАС" << endl;
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

    cout << "✅ Всього тваринок у масиві: " << animals.size() << "\n" << endl;

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
    cout << "              ДЕМОНСТРАЦІЯ ПОЛІМОРФІЗМУ" << endl;
    printSeparator();
    cout << "\n";
    
    cout << "📝 Зверніть увагу:" << endl;
    cout << "   1. Всі тварини створені через вказівники Animal*" << endl;
    cout << "   2. Кожна тварина викликає СВОЮ реалізацію sound() та type()" << endl;
    cout << "   3. Це і є ПОЛІМОРФІЗМ - різна поведінка через єдиний інтерфейс!" << endl;
    cout << "   4. Animal - абстрактний клас, що задає контракт для всіх тварин\n" << endl;

    printSeparator();
    cout << "           ТЕСТ ЗАВЕРШЕНО УСПІШНО!" << endl;
    printSeparator();
    cout << "\n";

    for (auto animal : animals) {
        delete animal;
    }
}
