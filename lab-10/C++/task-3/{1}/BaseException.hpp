#pragma once

#include <string>

using namespace std;

template<typename T>
class BaseException {
	private:
	  string message;
	  T invalidData;

	public:
	  BaseException(const string& message, const T& invalidData): message(message), invalidData(invalidData) {}

	  const string &getErrMsg() const { return message; }
  	  const T& getInvalidData() const { return invalidData; }
};