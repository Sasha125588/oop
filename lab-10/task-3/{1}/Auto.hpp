#include <string>
#include <cctype>
#include "WrongMaxSpeedException.hpp"
#include "WrongSpeedException.hpp"
#include "InvalidNumberException.hpp"

using namespace std;

class Auto {
    private:
    string number;
    int speed;
    int maxSpeed;

    bool isValidNumber(const string& num) const {
        if (num.length() != 8) return false;
        
        if (!isupper(num[0]) || !isupper(num[1])) return false;
        
        for (int i = 2; i < 6; i++) {
            if (!isdigit(num[i])) return false;
        }
        
        if (!isupper(num[6]) || !isupper(num[7])) return false;
        
        return true;
    }

    public:
    Auto(const string& number, int speed, int maxSpeed) : speed(0), maxSpeed(0) {
        if (!isValidNumber(number)) {
            throw InvalidNumberException(number, "Невірний формат номера. Очікується формат: AB1234CD");
        }
        
        if (maxSpeed > 360) {
            throw WrongMaxSpeedException(maxSpeed, "Максимальна швидкість не може перевищувати 360 км/год");
        }
        
        if (speed > maxSpeed) {
            throw WrongSpeedException(speed, "Швидкість не може перевищувати максимальну швидкість");
        }
        
        this->number = number;
        this->maxSpeed = maxSpeed;
        this->speed = speed;
    }

    const string& getNumber() const { return number; }
    void setNumber(const string& value) {
        if (!isValidNumber(value)) {
            throw InvalidNumberException(value, "Невірний формат номера. Очікується формат: AB1234CD");
        }
        this->number = value;
    }

    int getSpeed() const { return speed; }
    void setSpeed(int value) {
        if (value > maxSpeed) {
            throw WrongSpeedException(value, "Швидкість не може перевищувати максимальну швидкість");
        }
        this->speed = value;
    }

    int getMaxSpeed() const { return maxSpeed; }
    void setMaxSpeed(int value) {
        if (value > 360) {
            throw WrongMaxSpeedException(value, "Максимальна швидкість не може перевищувати 360 км/год");
        }
        
        if (speed > value) {
            throw WrongSpeedException(speed, "Поточна швидкість перевищує нову максимальну швидкість");
        }
        
        this->maxSpeed = value;
    }

    void increaseSpeed(int value = 5) {
        int newSpeed = this->speed + value;
        if (newSpeed > maxSpeed) {
            throw WrongSpeedException(newSpeed, "Збільшення швидкості призведе до перевищення максимальної швидкості");
        }
        this->speed = newSpeed;
    }

    void decreaseSpeed(int value = 5) {
        int newSpeed = this->speed - value;
        if (newSpeed < 0) {
            this->speed = 0;
        } else {
            this->speed = newSpeed;
        }
    }

};