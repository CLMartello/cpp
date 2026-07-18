
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Error\n", 1);
    std::string input = argv[1];
    try
    {
        RPN stack;
        stack.processExpression(input);
        std::cout << stack.getResult() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    return (0);
}