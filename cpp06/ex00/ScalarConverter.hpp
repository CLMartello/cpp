
#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID,
};

#include <string>

class	ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &copy);
	ScalarConverter &operator=(ScalarConverter &copy);
	~ScalarConverter();

public:
	//static method does not need a object
	static void convert(std::string &literal);

};

Type detectType(std::string &literal);
void printChar(std::string literal);
void printInt(double value);
void printFloat(double value);
void printDouble(double value);
void printNumber(std::string &literal);
void printPseudo(std::string &literal);

#endif
