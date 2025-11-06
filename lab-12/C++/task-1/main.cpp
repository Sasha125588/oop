#include <algorithm>
#include <cctype>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include "ranges"

using namespace std;

void print_list(const list<string>& l, const string& title = "") {
    if (!title.empty()) {
        cout << title << ": ";
    }
    cout << "[";
    bool first = true;
    for (const auto& word : l) {
        if (!first) cout << ", ";
        cout << "\"" << word << "\"";
        first = false;
    }
    cout << "]" << endl;
}

void print_deque(const deque<string>& d, const string& title = "") {
    if (!title.empty()) {
        cout << title << ": ";
    }
    cout << "[";
    for (size_t i = 0; i < d.size(); ++i) {
        cout << "\"" << d[i] << "\"";
        if (i < d.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    
    deque<string> words{"apple", "banana", "cherry", "date", "elderberry", 
                       "fig", "grape", "kiwi", "lemon", "mango"};

    cout << "Task 1: Find first word starting with a given letter" << endl;

    char search_letter;
    cout << "Enter a letter: ";
    cin >> search_letter;

    auto first_word = find_if(words.begin(), words.end(), [search_letter](const string& word) {
        return word[0] == search_letter;
    });

    if (first_word != words.end()) {
        cout << "Result: " << *first_word << endl;
    } else {
        cout << "Result: Not found" << endl;
    }

    cout << endl;

    cout << "Task 2: Count words with length greater than a given value" << endl;

    int min_length;
    cout << "Enter minimum length: ";
    cin >> min_length;

    auto count_words_longer_than = count_if(words.begin(), words.end(), [min_length](const string& word) {
        return word.length() > min_length;
    });

    cout << "Result: " << count_words_longer_than << " word(s) with length > " << min_length << endl;
    cout << endl;

    cout << "Task 3: Find longest and shortest words" << endl;

    auto longest_word = max_element(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    auto shortest_word = min_element(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    if (longest_word != words.end()) {
        cout << "Longest word: \"" << *longest_word << "\" (length: " << longest_word->length() << ")" << endl;
    }
    if (shortest_word != words.end()) {
        cout << "Shortest word: \"" << *shortest_word << "\" (length: " << shortest_word->length() << ")" << endl;
    }
    cout << endl;
    
    cout << "Task 4: Create list with last letter removed from each word" << endl;

    list<string> deque_to_list(words.size()); 

    // Щоб transform працював правильно потрібно попередньо виділити памʼять для deque_to_list(не менше ніж words.size())
    // або замість deque_to_list.begin() використати back_inserter(deque_to_list).
    // Якщо коротко, то back_inserter - "розумний" ітератор(вказівник) який при присвоєнні значення викликає push_back(),
    // тобто вставляє елемент в кінець колекції

    transform(words.cbegin(), words.cend(), deque_to_list.begin(), [](const string& word) {
        return word.substr(0, word.length() - 1); 
    }); 

    // В С++23 додали можливість писати так
    // deque_to_list = words | views::transform([](const string& word) { return word.substr(0, word.length() - 1); })
    //                       | ranges::to<list>();
    
    print_list(deque_to_list);

    cout << "Task 5: Sort deque in ascending (alphabetical) order" << endl;

    deque<string> words_ascending = words;

    // Можна використати вже готовий компаратор std::less || std::greater або написати власний

    // sort(d_descending.begin(), d_descending.end(), [](const string& a, const string& b) {
    //     return a > b;
    // });

    sort(words_ascending.begin(), words_ascending.end(), less<string>());

    print_deque(words_ascending, "Sorted ascending");
    cout << endl;

    cout << "Task 6: Sort deque in descending order" << endl;

    deque<string> words_descending = words;

    sort(words_descending.begin(), words_descending.end(), greater<string>());

    print_deque(words_descending, "Sorted ascending");
    cout << endl;

    cout << "Task 7: Sort by length (ascending), then alphabetically" << endl;
    deque<string> sorted_by_word_length = words;

    sort(sorted_by_word_length.begin(), sorted_by_word_length.end(), [](const string& a, const string& b) {
        if(a.length() == b.length())
            return a < b;
        return a.length() < b.length();
    });

    cout << "Task 8: Sort the list (from task 4) in ascending order" << endl;

    deque_to_list.sort();
    print_list(deque_to_list, "List sorted");

    cout << endl;

    cout << "Task 9: Remove words containing a given letter from the list" << endl;

    char letter_to_remove;
    cout << "Enter a letter to remove words containing it: ";
    cin >> letter_to_remove;

    deque_to_list.remove_if([letter_to_remove](const string& word) {
        return word.contains(letter_to_remove);
    });

    print_list(deque_to_list, "List after removal");
    cout << endl;

    cout << "Task 10: Convert all words in the list to uppercase" << endl;

    for_each(deque_to_list.begin(), deque_to_list.end(), [](string& word) {
        transform(word.begin(), word.end(), word.begin(), [](char c) {
            return toupper(c);
        });
    });

    // За допомогою ranges
    // std::ranges::for_each(deque_to_list, [](std::string& word) {
    //     std::ranges::transform(word, word.begin(), 
    //                           [](unsigned char c) { return std::toupper(c); });
    // });

    print_list(deque_to_list, "List in uppercase");
    cout << endl;
    
    return 0;
}