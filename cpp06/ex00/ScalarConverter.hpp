
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
	static void convert(std::string &literal);

};

Type detectType(std::string &literal);

#endif
