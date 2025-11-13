#include <string>
// #include <regex>

#include "WrongMaxSpeedException.hpp"
#include "WrongSpeedException.hpp"
#include "InvalidNumberException.hpp"

using namespace std;

class Auto {
    private:

    static constexpr int MAX_ALLOWED_SPEED = 360;
    static constexpr size_t NUMBER_LENGTH = 8;

    string number;
    int speed;
    int maxSpeed;
    
    // bool isValidNumber(const std::string& number) const {
    //     static const std::regex pattern("^[A-Z]{2}[0-9]{4}[A-Z]{2}$");
    //     return std::regex_match(number, pattern);
    // }
    
    bool isValidNumber(const string& number) const {
        if (number.length() != NUMBER_LENGTH) return false;
        
        if (!isupper(number[0]) || !isupper(number[1])) return false;
        
        for (int i = 2; i < 6; i++) {
            if (!isdigit(number[i])) return false;
        }
        
        if (!isupper(number[6]) || !isupper(number[7])) return false;
        
        return true;
    }

    public:
    Auto(const string& number, int speed, int maxSpeed): speed(0) {
      setNumber(number);
      setMaxSpeed(maxSpeed);
      setSpeed(speed);
    }

    const string& getNumber() const { return number; }
    void setNumber(const string& value) {
        if (!isValidNumber(value)) {
            throw InvalidNumberException("Невірний формат номера. Очікується формат: AB1234CD");
        }
        this->number = value;
    }

    int getSpeed() const { return speed; }
    void setSpeed(int value) {
        if (value > maxSpeed) {
            throw WrongSpeedException("Швидкість не може перевищувати максимальну швидкість");
        }
        this->speed = value;
    }

    int getMaxSpeed() const { return maxSpeed; }
    void setMaxSpeed(int value) {
        if (value > MAX_ALLOWED_SPEED) {
            throw WrongMaxSpeedException("Максимальна швидкість не може перевищувати 360 км/год");
        }
        
        if (speed > value) {
            throw WrongSpeedException("Поточна швидкість перевищує нову максимальну швидкість");
        }
        
        this->maxSpeed = value;
    }

    void increaseSpeed(int value = 5) {
        int newSpeed = this->speed + value;
        if (newSpeed > maxSpeed) {
            throw WrongSpeedException("Збільшення швидкості призведе до перевищення максимальної швидкості");
        }
        this->speed = newSpeed;
    }

    void decreaseSpeed(int value = 5) {
        this->speed = max(0, this->speed - value);
    }

};