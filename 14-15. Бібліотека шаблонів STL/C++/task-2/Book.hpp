#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book {
    private:
    string author;
    string name;
    int year;
    bool available; 

    public:
    Book(const string& author = "", const string& name = "", int year = 0, bool available = true)
        : author(author), name(name), year(year), available(available) {}

    string getAuthor() const { return author; }
    string getName() const { return name; }
    int getYear() const { return year; }
    bool isAvailable() const { return available; }

    void setAuthor(const string& a) { author = a; }
    void setName(const string& n) { name = n; }
    void setYear(int y) { year = y; }
    void setAvailable(bool a) { available = a; }

    bool operator<(const Book& other) const {
        if (author != other.author) {
            return author < other.author;
        }
        return name < other.name;
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "\"" << book.name << "\" by " << book.author 
           << " (" << book.year << ") - " 
           << (book.available ? "Available" : "Issued");
        return os;
    }
};


