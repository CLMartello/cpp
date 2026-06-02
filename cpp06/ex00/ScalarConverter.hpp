
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

public:
	static void convert(std::string literal);

};

Type detectType(std::string literal);

#endif
