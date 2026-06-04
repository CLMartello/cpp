
#include "ScalarConverter.hpp"
#include <string>

Type detectType(std::string literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
         literal == "-inff" || literal == "+inff" || literal == "nanf")
        return (PSEUDO);
    if (literal.length() == 1 && !isdigit(literal[0]))
        return (CHAR);
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (isdigit(literal[i]))
        i++;
    if (i == literal.length())
        return (INT);
    if (literal[i] == '.')
        i++;
    while (isdigit(literal[i]))
        i++;
    if (i == literal.length())
        return (DOUBLE);
    if (literal[i] == 'f' && i == (literal.length() - 1))
        return (FLOAT);
    return (INVALID);
}

static void convert(std::string literal) {

    Type type = detectType(literal);
    if (type == PSEUDO || type == INVALID)
        return (do something);
    for (int i = 0; i < 4; i++)
    {
        if (type != i)
        {
            convert_type[i];
            printf_type[i];
        }
    }
    //take literal, discover type
    //convert to char, int, float, double minus type
    //detect type
    //print type that are not original type

}

//pseudo-literal = valid inputs, but must not be converted
//double - nan = not a number
//double - inf = infinity
//double - -inf = negative infinity
//same meaning for float = nanf, +inff, -inff

//exceptions should not be add to class
//use the one already exist
//std::invalid_argument and std::out_of_range

