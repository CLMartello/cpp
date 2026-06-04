
#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "./conver literal" << std::endl;
        return (1);
    }
    try
    {
        std::string literal = argv[1];
        ScalarConverter::convert(literal);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}