
#include "iter.hpp"
#include <iostream>

void    function_numb(int &n)
{
    std::cout << n * 2 << std::endl;
}

void    function_str(std::string &word)
{
    std::cout << word.length() << std::endl;
}

void    function_char(char &c)
{
    std::cout << c << std::endl;
}

int main(void)
{
    std::cout << "Running function_numb:" << std::endl;
    int array_numb[5] = {1, 2, 3, 4, 5};
    iter(array_numb, 5, function_numb);
    std::cout << std::endl;

    std::cout << "Running function_str:" << std::endl;
    std::string array_str[3] = {"banana", "apple", "cherry"};
    iter(array_str, 3, function_str);
    std::cout << std::endl;

    std::cout << "Running function_char:" << std::endl;
    char array_char[4] = {'a', 'Y', '9', '&'};
    iter(array_char, 4, function_char);

    return (0);
}