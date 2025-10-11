#include "Library.hpp"
#include <iostream>

using namespace std;

void printSeparator(const string& title = "") {
    cout << "\n" << string(50, '=') << endl;
    if (!title.empty()) {
        cout << title << endl;
        cout << string(50, '=') << endl;
    }
}

int main()
{
    cout << "=== Lab 12 - Task 2: Library Management System ===" << endl;

    Library library;

    // 1. Додавання книг
    printSeparator("1. Adding Books");
    library.addBook(Book("George Orwell", "1984", 1949));
    library.addBook(Book("Harper Lee", "To Kill a Mockingbird", 1960));
    library.addBook(Book("George Orwell", "Animal Farm", 1945));
    library.addBook(Book("F. Scott Fitzgerald", "The Great Gatsby", 1925));
    library.addBook(Book("Jane Austen", "Pride and Prejudice", 1813));
    library.addBook(Book("J.K. Rowling", "Harry Potter and the Philosopher's Stone", 1997));
    library.addBook(Book("J.R.R. Tolkien", "The Hobbit", 1937));
    library.addBook(Book("J.R.R. Tolkien", "The Lord of the Rings", 1954));

    // 2. Вивід усіх книг
    printSeparator("2. Print All Books");
    library.printAllBooks();

    // 3. Пошук книги за автором і назвою
    printSeparator("3. Find Specific Book");
    cout << "Searching for '1984' by George Orwell:" << endl;
    library.searchAndPrintBook("George Orwell", "1984");

    // 4. Пошук книг за автором
    printSeparator("4. Find Books by Author");
    cout << "Searching for books by J.R.R. Tolkien:" << endl;
    auto tolkienBooks = library.findBooksByAuthor("J.R.R. Tolkien");
    for (const auto& book : tolkienBooks) {
        cout << "  - " << book << endl;
    }

    // 5. Видача книги
    printSeparator("5. Issue Book");
    library.issueBook("George Orwell", "1984");
    library.issueBook("J.K. Rowling", "Harry Potter and the Philosopher's Stone");

    // 6. Повернення книги
    printSeparator("6. Return Book");
    library.returnBook("George Orwell", "1984");

    // 7. Впорядкування книг
    printSeparator("7. Sort Books");
    library.sortBooks();
    library.printAllBooks();

    // 13. Обчислення книг певного автора (переміщено тут для логіки)
    printSeparator("8. Count Books by Author");
    library.countBooksByAuthor("George Orwell");
    library.countBooksByAuthor("J.R.R. Tolkien");

    // 11. Редагування книги за індексом
    printSeparator("9. Edit Book by Index");
    library.editBookByIndex(3, Book("Harper Lee", "To Kill a Mockingbird (Updated Edition)", 1960, true));

    // 12. Редагування книги за назвою та автором
    printSeparator("10. Edit Book by Author and Name");
    library.editBook("George Orwell", "Animal Farm", 
                     Book("George Orwell", "Animal Farm (2nd Edition)", 1945, true));
    library.printAllBooks();

    // 8. Вилучення конкретної книги
    printSeparator("11. Remove Specific Book");
    library.removeBook("F. Scott Fitzgerald", "The Great Gatsby", 1925);
    library.printAllBooks();

    // 9. Вилучення книг раніше заданого року
    printSeparator("12. Remove Books Before Year");
    library.removeBooksBeforeYear(1900);
    library.printAllBooks();

    // 10. Вилучення книги за індексом
    printSeparator("13. Remove Book by Index");
    library.removeBookByIndex(2);
    library.printAllBooks();

    // 16. Збереження у файл
    printSeparator("14. Save to File");
    library.saveToFile("library.txt");

    // 15. Доповнення бібліотеки (merge)
    printSeparator("15. Merge with External List");
    list<Book> externalBooks;
    externalBooks.push_back(Book("Ernest Hemingway", "The Old Man and the Sea", 1952, false));
    externalBooks.push_back(Book("Leo Tolstoy", "War and Peace", 1869));
    externalBooks.push_back(Book("Fyodor Dostoevsky", "Crime and Punishment", 1866));
    
    library.addBooks(externalBooks);
    library.printAllBooks();

    // Збереження оновленої бібліотеки
    library.saveToFile("library_updated.txt");

    // 17. Завантаження з файлу
    printSeparator("16. Load from File");
    Library newLibrary;
    newLibrary.loadFromFile("library_updated.txt");
    newLibrary.printAllBooks();

    // 14. Очистка бібліотеки
    printSeparator("17. Clear Library");
    library.clearLibrary();
    library.printAllBooks();

    printSeparator("All tasks completed!");
    
    return 0;
}
