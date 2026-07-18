#include "MutantStack.hpp"
#include <iostream>


int main()
{
    std::cout << "Basic tests: " << std::endl << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop one: " << mstack.size() << std::endl << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(4);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "Elements of stack using iterator" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);

    std::cout << "Size of copied stack: " << s.size() << std::endl;

    std::cout << "Methods of stack in MutantStack" << std::endl;
    std::cout << "top(): " << mstack.top() << std::endl;
    std::cout << "empty(): " << mstack.empty() << std::endl;
    s.pop();
    std::cout << "top() after pop(): " << mstack.top() << std::endl;
    s.push(555);
    std::cout << "top() after push(555): " << mstack.top() << std::endl << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << "Elements of stack using reverse_iterator" << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}