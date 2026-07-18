#include "Span.hpp"

#include <deque>

int main()
{
    try
    {
        std::cout << "Basic test:" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    try
    {
        std::cout << "Exception of span:" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Exception of size:" << std::endl;
        Span sp = Span(2);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Test thousands of numbers:" << std::endl;
        Span spc = Span(11000);
        std::vector<int> v;

        for (size_t i = 0; i < 11000; ++i)
            v.push_back(i);

        spc.addNumber(v.begin(), v.end());
        std::cout << spc.shortestSpan() << std::endl;
        std::cout << spc.longestSpan() << std::endl;        
        std::cout << std::endl;

        std::cout << "Add one more number:" << std::endl;
        spc.addNumber(11001);

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Test more numbers than size:" << std::endl;
        Span spc = Span(10000);
        std::vector<int> v;

        for (size_t i = 0; i < 11000; ++i)
            v.push_back(i);

        spc.addNumber(v.begin(), v.end());
        std::cout << spc.shortestSpan() << std::endl;
        std::cout << spc.longestSpan() << std::endl;        
        std::cout << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}