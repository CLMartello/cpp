
#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy) : _stack(copy._stack) {}

RPN& RPN::operator=(const RPN& copy)
{
    if (this != &copy)
    {
        this->_stack = copy._stack;
    }
    return (*this);
}

void RPN::applyOperator(std::string oper)
{
    int nbr2 = _stack.top();
    _stack.pop();
    int nbr1 = _stack.top();
    _stack.pop();
    int res;
    if (oper == "+")
        res = nbr1 + nbr2;
    else if (oper == "-")
        res = nbr1 - nbr2;
    else if (oper == "*")
        res = nbr1 * nbr2;
    else if (oper == "/")
    {
        if (nbr2 == 0)
            throw std::runtime_error("Error\n");
        res = nbr1 / nbr2;
    }
    _stack.push(res);
}

void RPN::processExpression(std::string input)
{
    std::stringstream ss(input);
    std::string token;
    while (ss >> token)
    {
        if (isdigit(token[0]))
            _stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error\n");
            applyOperator(token);
        }
        else
            throw std::runtime_error("Error\n");
    }
}

int RPN::getResult()
{
    int result = _stack.top();
    return(result);
}
