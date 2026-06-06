
#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <iomanip>

Type detectType(std::string &literal)
{
    bool dot = false;

    if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
         literal == "-inff" || literal == "+inff" || literal == "nanf")
        return (PSEUDO);
    if (literal.length() == 1 && !isdigit(literal[0]))
        return (CHAR);
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (i < literal.length() && isdigit(literal[i]))
        i++;
    if (i == literal.length())
        return (INT);
    if (i < literal.length() && literal[i] == '.')
    {
        dot = true;
        i++;
    }
    while (i < literal.length() && isdigit(literal[i]))
        i++;
    if (i == literal.length())
        return (DOUBLE);
    if (dot && literal[i] == 'f' && i == (literal.length() - 1))
        return (FLOAT);
    return (INVALID);
}

void printInt(double value)
{
    if (value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(double value)
{
    if (value > FLT_MAX || value < -FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}

void printDouble(double value)
{
    if (value > DBL_MAX || value < -DBL_MAX)
        std::cout << "double: impossible" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
}

void printNumber(std::string &literal)
{
    //static_cast does not convert string to number
    //it only converts among numeric types
    //strod = parses the string and createe a double
    double value = std::strtod(literal.c_str(), NULL);
    if (value > 31 && value < 127)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void printChar(std::string literal)
{
    char value = literal[0];
    if (value > 31 && value < 127)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void    printPseudo(std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

//static in the .cpp file means free function, only visible in this file
void ScalarConverter::convert(std::string &literal) {

    Type type = detectType(literal);
    switch(type)
    {
        case CHAR:
        {
            printChar(literal);
            break;
        }
        case INT:
        case FLOAT:
        case DOUBLE:
        {
            printNumber(literal);
            break;
        }
        case PSEUDO:
        {
            printPseudo(literal);
            break;
        }
        default:
            std::cout << "Invalid" << std::endl;
    }
}
