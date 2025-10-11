#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <string>

using namespace std;

void printDeque(const deque<string>& d, const string& title = "") {
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

void printList(const list<string>& l, const string& title = "") {
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

int main()
{
    deque<string> d = {"apple", "banana", "cherry", "date", "elderberry", 
                       "fig", "grape", "kiwi", "lemon", "mango"};
    
    cout << "=== Lab 12 - Task 1: STL Algorithms with Deque ===" << endl << endl;
    cout << "Initial deque: ";
    printDeque(d);
    cout << endl;

    cout << "Task 1: Find first word starting with a given letter" << endl;
    char searchLetter;
    cout << "Enter a letter: ";
    cin >> searchLetter;
    
    auto res1 = find_if(d.begin(), d.end(), [searchLetter](const string& word) {
        return !word.empty() && word[0] == searchLetter;
    });
    
    if (res1 != d.end()) {
        cout << "Result: \"" << *res1 << "\"" << endl;
    } else {
        cout << "Result: Not found" << endl;
    }
    cout << endl;

    cout << "Task 2: Count words with length greater than a given value" << endl;
    int minLength;
    cout << "Enter minimum length: ";
    cin >> minLength;
    
    int count = count_if(d.begin(), d.end(), [minLength](const string& word) {
        return word.length() > minLength;
    });
    
    cout << "Result: " << count << " word(s) with length > " << minLength << endl;
    cout << endl;

    cout << "Task 3: Find longest and shortest words" << endl;
    
    auto longest = max_element(d.begin(), d.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    
    auto shortest = min_element(d.begin(), d.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    
    if (longest != d.end()) {
        cout << "Longest word: \"" << *longest << "\" (length: " << longest->length() << ")" << endl;
    }
    if (shortest != d.end()) {
        cout << "Shortest word: \"" << *shortest << "\" (length: " << shortest->length() << ")" << endl;
    }
    cout << endl;

    cout << "Task 4: Create list with last letter removed from each word" << endl;
    list<string> dequeToList;
    
    transform(d.begin(), d.end(), back_inserter(dequeToList), [](const string& word) {
        if (word.length() > 0) {
            return word.substr(0, word.length() - 1);
        }
        return string("");
    });
    
    printList(dequeToList, "List");
    cout << endl;

    cout << "Task 5: Sort deque in ascending (alphabetical) order" << endl;
    deque<string> d_ascending = d;
    sort(d_ascending.begin(), d_ascending.end());
    printDeque(d_ascending, "Sorted ascending");
    cout << endl;

    cout << "Task 6: Sort deque in descending order" << endl;
    deque<string> d_descending = d;
    sort(d_descending.begin(), d_descending.end(), [](const string& a, const string& b) {
        return a > b;
    });
    printDeque(d_descending, "Sorted descending");
    cout << endl;

    cout << "Task 7: Sort by length (ascending), then alphabetically" << endl;
    deque<string> d_length_sorted = d;
    sort(d_length_sorted.begin(), d_length_sorted.end(), [](const string& a, const string& b) {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }
        return a < b;
    });
    printDeque(d_length_sorted, "Sorted by length");
    cout << endl;

    cout << "Task 8: Sort the list (from task 4) in ascending order" << endl;
    dequeToList.sort();
    printList(dequeToList, "List sorted");
    cout << endl;

    cout << "Task 9: Remove words containing a given letter from the list" << endl;
    char letterToRemove;
    cout << "Enter a letter to remove words containing it: ";
    cin >> letterToRemove;
    
    dequeToList.remove_if([letterToRemove](const string& word) {
        return word.find(letterToRemove) != string::npos;
    });
    
    printList(dequeToList, "List after removal");
    cout << endl;

    cout << "Task 10: Convert all words in the list to uppercase" << endl;
    for (auto& word : dequeToList) {
        transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
            return toupper(c);
        });
    }
    printList(dequeToList, "List in uppercase");
    cout << endl;

    cout << "=== All tasks completed ===" << endl;

    return 0;
}
