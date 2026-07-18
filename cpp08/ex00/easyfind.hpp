#ifndef EASYFIND_HPP

#define EASYFIND_HPP

#include <exception>
#include <iostream>
#include <algorithm>

//iterator is an object that behaves like a pointer
//poiting to the elements of a container
template <typename T> void easyfind(T& container, int value)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        std::cout << "Value " << value << " found!" << std::endl;
    else
        throw std::runtime_error("Value not found!\n");
}

template <typename T> void easyfind(const T& container, int value)
{
    typename T::const_iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        std::cout << "Value " << value << " found!" << std::endl;
    else
        throw std::runtime_error("Value not found!\n");
}

#endif