#pragma once

#include <string>

using namespace std;

class Chapter {
    private:
    string title;
    string content;

    public:
    Chapter(const string& title, const string& content) : title(title), content(content) {}
    
    string getTitle() const { return title; }
    void setTitle(const string& title) { this->title = title; }
    
    string getContent() const { return content; }
    void setContent(const string& content) { this->content = content; }
};