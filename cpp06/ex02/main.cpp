
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(std::time(0));

    Base *one = generate();
    Base *two = generate();
    Base *tree = generate();
    Base *four = generate();
    std::cout << std::endl;

    identify(one);
    identify(two);
    identify(tree);
    identify(four);
    std::cout << std::endl;

    identify(*one);
    identify(*two);
    identify(*tree);
    identify(*four);
    std::cout << std::endl;

    delete one;
    delete two;
    delete tree;
    delete four;

}