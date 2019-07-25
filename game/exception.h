#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class InvalidPosition{
	std::string s;
public:
	InvalidPosition(std::string s);
	std::string getErrorMessage();
};

class ExceedMaximum{
	std::string s;
public:
	ExceedMaximum(std::string s);
	std::string getErrorMessage();
};

#endif
