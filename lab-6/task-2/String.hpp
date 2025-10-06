#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;

class String {
private:
  string str;
  
  map<char, int> createCharCount(const string& s) const {
    map<char, int> charCount;
    for (auto c : s) {
      charCount[c]++;
    }
    return charCount;
  }

public:
  String(const char *s) { 
    if (s) str = s; 
  }
  
  String(const String &other) { 
    str = other.str; 
  }
  
  String(const string &other) { 
    str = other; 
  }

  String operator+(const String &other) const {
    String newString = *this;
    newString.str += other.str;
    return newString;
  };

  String operator+(const string &other) const {
    String newString = *this;
    newString.str += other;
    return newString;
  }

  String operator+(const char *other) const {
    String newString = *this;
    newString.str += other;
    return newString;
  }

  String operator*(const String &other) const {
    string result;
    map<char, int> charCount = createCharCount(other.str);

    for (auto c : str) {
      if (charCount[c]) {
        result += c;
      }
    }

    return String(result);
  }

  String operator/(const String &other) const {
    string result;
    map<char, int> charCount = createCharCount(other.str);

    for (auto c : str) {
      if (!charCount[c]) {
        result += c;
      }
    }

    return String(result);
  }

  String &operator++() {
    for (char &c : str) {
      ++c;
    }
    return *this;
  }

  String operator++(int) {
    String temp = *this;
    ++(*this);
    return temp;
  }

  bool operator==(const String &other) const {
    return strcmp(str.c_str(), other.str.c_str()) == 0;
  }

  bool operator!=(const String &other) const {
    return strcmp(str.c_str(), other.str.c_str()) != 0;
  }

  bool operator<(const String &other) const {
    return strcmp(str.c_str(), other.str.c_str()) < 0;
  }

  bool operator>(const String &other) const {
    return strcmp(str.c_str(), other.str.c_str()) > 0;
  }

  bool operator<=(const String &other) const {
    return strcmp(str.c_str(), other.str.c_str()) <= 0;
  }

  bool operator>=(const String &other) const {
    return strcmp(str.c_str(), other.str.c_str()) >= 0;
  }

  String operator!() const {
    String reversed = str;
    int l = 0, r = reversed.str.length() - 1;

    while (l < r) {
      swap(reversed[l], reversed[r]); // str[l], str[r] = str[r], str[l] так можна?
      l++;
      r--;
    }

    return reversed;
  }

  const char operator[](int index) const {
    if(index < 0 || index >= str.length()) {
      throw out_of_range("String index out of range");
    }
    return str[index];
  }

  char& operator[](int index) {
    if(index < 0 || index >= str.length()) {
      throw out_of_range("String index out of range");
    }
    return str[index];
  }

  String operator()(int start, int length = 0) const {
    if (start < 0 || start >= str.length()) {
      return "";
    }

    if (length <= 0 || start + length > str.length()) {
      return str.substr(start).c_str();
    }

    return str.substr(start, length).c_str();
  }

  String& operator=(const String& other) {
    str = other.str;
    return *this;
  }

  operator int() const {
    return atoi(str.c_str());
  }

  friend std::ostream& operator<< (std::ostream &out, const String& string) {
    out << "String: " << string.str << endl;
    return out;
  }

  friend std::istream& operator>>(std::istream &in, String& string) {
    in >> string.str;
    return in;
  }
};
