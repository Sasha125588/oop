#include <iostream>
#include "Book.hpp"
#include "Chapter.hpp"
#include <vector>

using namespace std;

void testBookManagement();

int main()
{
    testBookManagement();
    return 0;
}

void testBookManagement() {
    cout << "========================================" << endl;
    cout << "   ТЕСТУВАННЯ УПРАВЛІННЯ КНИГАМИ" << endl;
    cout << "========================================" << endl << endl;

    // ========== ТЕСТ 1: Створення книги та додавання розділів ==========
    cout << "=== ТЕСТ 1: Створення книги та додавання розділів ===" << endl;
    
    Book* book1 = new Book("Програмування на C++", {});
    
    cout << "✓ Створено книгу: Програмування на C++" << endl;
    cout << "Початковий стан книги:" << endl;
    book1->listChapters();
    
    cout << "Додаємо розділи до книги..." << endl;
    book1->addChapter(new Chapter("Вступ до C++", "Базові концепції мови C++"));
    book1->addChapter(new Chapter("Об'єктно-орієнтоване програмування", "Класи, об'єкти, наслідування"));
    book1->addChapter(new Chapter("Стандартна бібліотека", "Контейнери, алгоритми, ітератори"));
    book1->addChapter(new Chapter("Просунуті теми", "Шаблони, виключення, багатопоточність"));
    
    cout << "Стан книги після додавання розділів:" << endl;
    book1->listChapters();

    // ========== ТЕСТ 2: Видалення розділів ==========
    cout << "=== ТЕСТ 2: Видалення розділів ===" << endl;
    
    cout << "Видаляємо розділ 2 (Об'єктно-орієнтоване програмування)..." << endl;
    book1->removeChapter(1);  // Індекси починаються з 0
    
    cout << "Стан книги після видалення розділу:" << endl;
    book1->listChapters();
    
    cout << "Видаляємо перший розділ (Вступ до C++)..." << endl;
    book1->removeChapter(0);
    
    cout << "Стан книги після видалення ще одного розділу:" << endl;
    book1->listChapters();

    // ========== ТЕСТ 3: Робота з кількома книгами ==========
    cout << "=== ТЕСТ 3: Робота з кількома книгами ===" << endl;
    
    Book* book2 = new Book("Алгоритми та структури даних", {});
    book2->addChapter(new Chapter("Основи алгоритмів", "Аналіз складності, O-нотація"));
    book2->addChapter(new Chapter("Сортування", "Методи сортування та їх складність"));
    
    Book* book3 = new Book("Шаблони проектування", {});
    book3->addChapter(new Chapter("Породжувальні шаблони", "Singleton, Factory, Builder"));
    book3->addChapter(new Chapter("Структурні шаблони", "Adapter, Decorator, Composite"));
    book3->addChapter(new Chapter("Поведінкові шаблони", "Observer, Strategy, Command"));
    
    cout << "✓ Створено додаткові книги:" << endl;
    cout << "\nКнига 2:" << endl;
    book2->listChapters();
    
    cout << "\nКнига 3:" << endl;
    book3->listChapters();

    // ========== ТЕСТ 4: Видалення книг ==========
    cout << "=== ТЕСТ 4: Видалення книг ===" << endl;
    
    cout << "Видаляємо книгу 'Алгоритми та структури даних'..." << endl;
    delete book2;
    book2 = nullptr;
    cout << "✓ Книгу видалено (включно з усіма розділами)" << endl;
    
    // ========== ТЕСТ 5: Робота з розділами ==========
    cout << "=== ТЕСТ 5: Робота з розділами ===" << endl;
    
    cout << "Отримуємо доступ до розділу книги 'Шаблони проектування':" << endl;
    Chapter* chapter = book3->getChapter(1);
    cout << "Розділ: " << chapter->getTitle() << endl;
    cout << "Зміст: " << chapter->getContent() << endl << endl;
    
    cout << "Змінюємо заголовок розділу..." << endl;
    chapter->setTitle("Структурні шаблони проектування");
    
    cout << "Оновлений список розділів:" << endl;
    book3->listChapters();

    // ========== ТЕСТ 6: Очищення пам'яті ==========
    cout << "=== ТЕСТ 6: Очищення пам'яті ===" << endl;
    
    cout << "Видаляємо всі книги..." << endl;
    delete book1;
    delete book3;
    cout << "✓ Всі книги видалено (включно з усіма розділами)" << endl;
    
    cout << "========================================" << endl;
    cout << "       ТЕСТУВАННЯ ЗАВЕРШЕНО" << endl;
    cout << "========================================" << endl;
}