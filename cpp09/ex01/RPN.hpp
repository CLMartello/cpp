#ifndef RPN_HPP

#define RPN_HPP

#include <stack>
#include <sstream>
#include <exception>
#include <iostream>

class RPN
{
private:
    std::stack<int> _stack;
public:
    RPN();
    ~RPN();
    RPN(const RPN& copy);
    RPN& operator=(const RPN& copy);

    void processExpression(std::string input);
    void applyOperator(std::string oper);
    int getResult();
};

#endif