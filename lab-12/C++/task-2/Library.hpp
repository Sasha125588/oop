#pragma once

#include "Book.hpp"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <list>

using namespace std;

class Library {
private:
    list<Book> lib;

    // Допоміжна функція для регістро-незалежного порівняння рядків
    static string toLower(const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), 
                  [](char c) { return tolower(c); });
        return result;
    }

    // Компаратор для сортування книг (за автором, потім за назвою)
    static bool compareBooks(const Book& a, const Book& b) {
        string authorA = toLower(a.getAuthor());
        string authorB = toLower(b.getAuthor());
        
        if (authorA != authorB) {
            return authorA < authorB;
        }
        
        string nameA = toLower(a.getName());
        string nameB = toLower(b.getName());
        return nameA < nameB;
    }

public:
    Library() {
        cout << "Library created." << endl;
    }
    Library(const string& filename) {
        cout << "Library created from file: " << filename << endl;
        loadFromFile(filename);
    }
    Library(list<Book> lib) {
        cout << "Library created from list: " << endl;
        this->lib = lib;
    }

    ~Library() {
        cout << "Library destroyed. Total books: " << lib.size() << endl;
    }

    void addBook(const Book& book) {
        lib.push_back(book);
        cout << "Book added: " << book << endl;
    }

    void printAllBooks() const {
        if (lib.empty()) {
            cout << "Library is empty." << endl;
            return;
        }
        
        cout << "\n=== Library Books ===" << endl;
        int index = 1;
        for (const auto& book : lib) {
            cout << index++ << ". " << book << endl;
        }
        cout << "Total books: " << lib.size() << endl << endl;
    }

    // 3. Пошук книги (задано автор та назва)
    list<Book>::iterator findBook(const string& author, const string& name) {
        return find_if(lib.begin(), lib.end(), [&author, &name](const Book& b) {
            return b.getAuthor() == author && b.getName() == name;
        });
    }

    // Пошук і вивід результату
    void searchAndPrintBook(const string& author, const string& name) {
        auto it = findBook(author, name);
        if (it != lib.end()) {
            cout << "Found: " << *it << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    // 4. Пошук книг заданого автора
    list<Book> findBooksByAuthor(const string& author) const {
        list<Book> result;
        for (const auto& book : lib) {
            if (book.getAuthor() == author) 
                result.push_back(book);
            
        }
        return result;
    }

    // 5. Видача книги (книга відмічається як видана)
    bool issueBook(const string& author, const string& name) {
        auto it = findBook(author, name);
        if (it == lib.end()) {
            cout << "Book not found." << endl;
            return false;
        }

        if (!it->isAvailable()) {
            cout << "Book is already issued." << endl;
            return false;
        }

        it->setAvailable(false);
        cout << "Book issued: " << *it << endl;
        return true;
    }

    // 6. Повернення книги у бібліотеку
    bool returnBook(const string& author, const string& name) {
        auto it = findBook(author, name);
        if (it == lib.end()) {
            cout << "Book not found." << endl;
            return false;
        }
        
        if (it->isAvailable()) {
            cout << "Book is already in library." << endl;
            return false;
        }

        it->setAvailable(true);
        cout << "Book returned: " << *it << endl;
        return true;
    }

    // 7. Впорядкування книг за автором, потім за назвою
    void sortBooks() {
        lib.sort(compareBooks);
        cout << "Books sorted by author and name." << endl;
    }

    // 8. Вилучення книги (задано автор, назва та рік)
    bool removeBook(const string& author, const string& name, int year) {
        int initialSize = lib.size();
        lib.remove_if([&author, &name, year](const Book& b) {
            return b.getAuthor() == author && b.getName() == name && b.getYear() == year;
        });
        
        if (lib.size() == initialSize) {
            cout << "Book not found." << endl;
            return false;
        }
        
        cout << "Book removed: \"" << name << "\" by " << author << " (" << year << ")" << endl;
        return true;
    }

    // 9. Вилучення книг, виданих раніше заданого року
    int removeBooksBeforeYear(int year) {
        int initialSize = lib.size();
        lib.remove_if([year](const Book& b) {
            return b.getYear() < year;
        });
        
        int removed = initialSize - lib.size();
        cout << "Removed " << removed << " book(s) published before " << year << endl;
        return removed;
    }

    // 10. Вилучення книги за індексом (валідація індексу)
    bool removeBookByIndex(int index) {
        if (index < 0 || index >= lib.size()) {
            cout << "Invalid index. Library has " << lib.size() << " books (indices 0-" 
                 << lib.size() - 1 << ")" << endl;
            return false;
        }

        auto it = lib.begin();
        advance(it, index);
        cout << "Removing book at index " << index << ": " << *it << endl;
        lib.erase(it);
        return true;
    }

    // 11. Редагування книги за індексом (валідація)
    bool editBookByIndex(int index, const Book& newBook) {
        if (index < 0 || index >= lib.size()) {
            cout << "Invalid index. Library has " << lib.size() << " books (indices 0-" 
                 << lib.size() - 1 << ")" << endl;
            return false;
        }

        auto it = lib.begin();
        advance(it, index);
        cout << "Editing book at index " << index << endl;
        cout << "Old: " << *it << endl;
        *it = newBook;
        cout << "New: " << *it << endl;
        return true;
    }

    // 12. Редагування книги за назвою та автором
    bool editBook(const string& author, const string& name, const Book& newBook) {
        auto it = findBook(author, name);
        if (it == lib.end()) {
            cout << "Book not found." << endl;
            return false;
        }
        
        cout << "Editing book: \"" << name << "\" by " << author << endl;
        cout << "Old: " << *it << endl;
        *it = newBook;
        cout << "New: " << *it << endl;
        return true;
    }

    // 13. Обчислення книг певного автора
    int countBooksByAuthor(const string& author) const {
        int count = count_if(lib.begin(), lib.end(), [&author](const Book& b) {
            return b.getAuthor() == author;
        });
        cout << "Books by " << author << ": " << count << endl;
        return count;
    }

    // 14. Очистка бібліотеки (вилучення усіх книг)
    void clearLibrary() {
        lib.clear();
        cout << "Library cleared." << endl;
    }

    // 15. Доповнення бібліотеки книгами із зовнішнього списку (merge)
    void addBooks(list<Book>& other) {
        if (other.empty()) {
            cout << "External list is empty." << endl;
            return;
        }

        // Обидва списки мають бути відсортовані для merge
        sortBooks();
        other.sort(compareBooks);
        lib.merge(other, compareBooks);

        cout << "Books merged successfully. Total books: " << lib.size() << endl;
    }

    bool saveToFile(const string& filename = "lib.txt") const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Cannot open file for writing: " << filename << endl;
            return false;
        }

        for (const auto& book : lib) {
            file << book.getAuthor() << "|" 
                 << book.getName() << "|" 
                 << book.getYear() << "|" 
                 << book.isAvailable() << endl;
        }

        file.close();
        cout << "Library saved to file: " << filename << endl;
        return true;
    }

    bool loadFromFile(const string& filename = "lib.txt") {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Cannot open file for reading: " << filename << endl;
            return false;
        }

        lib.clear();
        string author, name;
        int year;
        bool available;
        string line;

        while (getline(file, line)) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            size_t pos3 = line.find('|', pos2 + 1);

            if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
                author = line.substr(0, pos1);
                name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                year = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                available = (line.substr(pos3 + 1) == "1");

                lib.push_back(Book(author, name, year, available));
            }
        }

        file.close();
        cout << "Library loaded from file: " << filename << " (" << lib.size() << " books)" << endl;
        return true;
    }

    size_t size() const {
        return lib.size();
    }

    bool empty() const {
        return lib.empty();
    }
};

