#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unordered_map>

using namespace std;

class String
{
private:
  static constexpr size_t npos = -1;

  char *data;
  size_t len;

  unordered_map<char, int> createCharCount(const char *str) const
  {
    unordered_map<char, int> charCount;
    for (int i = 0; i < str[i] != '\0'; i++)
    {
      charCount[str[i]]++;
    }
    return charCount;
  }

  String substr(size_t start, size_t n) const
  {
    if (start >= len)
    {
      return String("");
    }

    if (start + n > len)
    {
      n = len - start;
    }

    char *newData = new char[n + 1];
    strncpy(newData, data + start, n);
    newData[n] = '\0';

    String result(newData);
    delete[] newData;
    return result;
  }

  String substr(size_t start) const
  {
    return substr(start, len - start);
  }

  void ensureNotEmpty() const
  {
    if (len == 0)
      throw runtime_error("String is empty");
  }

  void ensureValidIndex(int index) const
  {
    if (index < 0 || index >= len)
      throw out_of_range("Index out of bounds");
  }

public:
  String() : data(new char[1]{'\0'}), len(0) {}

  String(const char *s) : data(), len()
  {
    if (!s)
      s = "";

    len = strlen(s);
    data = new char[len + 1];
    strcpy(data, s);
  }

  String(const String &other) : len(other.len)
  {
    data = new char[len + 1];
    std::strcpy(data, other.data);
  }

  ~String()
  {
    if (data)
      delete[] data;
  }

  String operator+(const String &other) const
  {
    int newLen = len + other.len;

    char *newData = new char[newLen + 1];

    strcpy(newData, data);
    strcat(newData, other.data);

    String result(newData);
    delete[] newData;
    return result;
  };

  String operator+(const char *other) const
  {
    int otherLen = strlen(other);
    int newLen = len + otherLen;

    char *newData = new char[newLen + 1];

    strcpy(newData, data);
    strcat(newData, other);

    String result(newData);
    delete[] newData;
    return result;
  }

  String operator*(const String &other) const
  {
    char *result = new char[len + 1](); // {'\0'}

    unordered_map<char, int> charCount = createCharCount(other.data);

    int pos = 0;

    for (int i = 0; i < len; i++)
    {
      char c = data[i];

      if (charCount[c])
      {
        result[pos++] = c;
      }
    }

    result[pos] = '\0';

    String temp(result);
    delete[] result;
    return temp;

    // return String(result);
  }

  String operator/(const String &other) const
  {
    char *result = new char[len + 1](); // {'\0'}

    unordered_map<char, int> charCount = createCharCount(other.data);

    int pos = 0;

    for (int i = 0; i < len; i++)
    {
      char c = data[i];

      if (!charCount[c])
      {
        result[pos++] = c;
      }
    }

    result[pos] = '\0';

    String temp(result);
    delete[] result;
    return temp;
  }

  String &operator++()
  {
    for (int i = 0; i < len; i++)
    {
      ++data[i];
    }

    return *this;
  }

  String operator++(int)
  {
    String temp = *this;
    ++(*this);
    return temp;
  }

  bool operator<(const String &other) const
  {
    return strcmp(data, other.data) < 0;
  }

  bool operator>(const String &other) const
  {
    return other < *this;
  }

  bool operator<=(const String &other) const
  {
    return !(other < *this);
  }

  bool operator>=(const String &other) const
  {
    return !(*this < other);
  }

  bool operator==(const String &other) const
  {
    return strcmp(data, other.data) == 0;
  }

  bool operator!=(const String &other) const
  {
    return !(*this == other);
  }

  String operator!() const
  {
    String reversed = *this;
    int l = 0, r = reversed.len - 1;

    while (l < r)
    {
      swap(reversed[l], reversed[r]); // str[l], str[r] = str[r], str[l] так можна?
      l++;
      r--;
    }

    return reversed;
  }

  const char operator[](int index) const
  {
    ensureNotEmpty();
    ensureValidIndex(index);

    return data[index];
  }

  char &operator[](int index)
  {
    ensureNotEmpty();
    ensureValidIndex(index);

    return data[index];
  }

  String operator()(size_t start, size_t n = npos) const
  {
    if (n == npos || start + n > len)
    {
      return substr(start);
    }

    return substr(start, n);
  }

  String &operator=(const String &other)
  {
    if (this == &other)
      return *this;

    delete[] data;

    len = other.len;
    data = new char[len + 1];
    strcpy(data, other.data);

    return *this;
  }

  operator int() const
  {
    return atoi(data);
  }

  friend std::ostream &operator<<(std::ostream &out, const String &string)
  {
    out << string.data;

    return out;
  }

  friend std::istream &operator>>(std::istream &in, String &string)
  {
    char buffer[1024];
    in >> buffer;
    string = String(buffer);

    return in;
  }
};
