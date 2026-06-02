
#include "ScalarConverter.hpp"
#include <string>

Type detectType(std::string literal)
{
    //char = single char printable
    if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
         literal == "-inff" || literal == "+inff" || literal == "nanf")
        return (PSEUDO);
    if (literal.length() == 1 && !isdigit(literal[0]))
        return (CHAR);
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]))
            break;
    }
    if (i == literal.length())
        return (INT);
    

    return (INVALID);
}

// static void convert(std::string literal) {

//     //take literal, discover type
//     //convert to char, int, float, double minus type
//     //detect type
//     //print type that are not original type

// }

//pseudo-literal = valid inputs, but must not be converted
//double - nan = not a number
//double - inf = infinity
//double - -inf = negative infinity
//same meaning for float = nanf, +inff, -inff

//exceptions should not be add to class
//use the one already exist
//std::invalid_argument and std::out_of_range

