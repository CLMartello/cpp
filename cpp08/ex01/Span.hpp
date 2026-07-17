#ifndef SPAN_HPP

#define SPAN_HPP

#include <vector>
#include <exception>
#include <climits>
#include <iostream>
#include <algorithm>

class Span
{
private:
    unsigned int N;
    std::vector<int> container;
public:
    Span();
    Span(unsigned int N);
    ~Span();
    Span(const Span& copy);
    Span& operator=(const Span& copy);

    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;

};

#endif