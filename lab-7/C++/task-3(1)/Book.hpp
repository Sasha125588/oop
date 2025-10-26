#pragma once

#include "Chapter.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Book {
    private:
    string bookTitle;
	vector<Chapter*> chapters;

    public:
    Book(const string& bookTitle, vector<Chapter*> chapters): bookTitle(bookTitle), chapters(chapters) {}
    Book() = default;

    ~Book() {
        for (auto chapter : chapters) {
            cout << "Видалено частину " << chapter->getTitle() << endl;
            delete chapter;
        }
    }

    Book& addChapter(Chapter* chapter) {
        chapters.push_back(chapter);
        return *this;
    }

	Book& removeChapter(int index) {
        if (index >= 0 && index < chapters.size()) {
            delete chapters[index];
            chapters.erase(chapters.begin() + index);
        }
        return *this;
    }; 

	Chapter* getChapter(int index) {
        if (index >= 0 && index < chapters.size()) {
            return chapters[index];
        }
        return nullptr;
    };

	void listChapters() {
        cout << "=== Список розділів книги: " << bookTitle << " ===" << endl;
    
        if (chapters.empty()) {
            cout << "Книга не містить розділів." << endl;
            return;
        }
        
        cout << "Загальна кількість розділів: " << chapters.size() << endl << endl;
        
        for (size_t i = 0; i < chapters.size(); i++) {
            cout << "Розділ " << (i + 1) << ": " << chapters[i]->getTitle() << endl;
        }
        
        cout << endl;
    };
};