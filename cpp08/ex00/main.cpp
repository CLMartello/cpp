
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    try
    {        
        std::vector<int> v;
        for (int i = 0; i < 5; i++)
            v.push_back(i);
        std::cout << "Vector: ";
        for (size_t i = 0; i < v.size(); i++)
            std::cout << v[i] << " ";
        std::cout << std::endl << std::endl;
        std::cout << "Success:" << std::endl;
        ::easyfind(v, 2);
        std::cout << std::endl;
        std::cout << "Fail:" << std::endl;
        ::easyfind(v, 8);
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    try
    {
        std::list<int> l;
        for (int i = 2; i < 7; i++)
        {
            if (i % 2)
                l.push_front(i);
            else
                l.push_back(i);
        }
        std::cout << "List: ";
        std::list<int>::iterator it;
        for (it = l.begin(); it != l.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl << std::endl;      
        std::cout << "Success:" << std::endl;
        ::easyfind(l, 2);
        std::cout << std::endl;
        std::cout << "Fail:" << std::endl;
        ::easyfind(l, 8);
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    return (0);
}