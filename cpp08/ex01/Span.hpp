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

//iterator is an object that points to the elements of a container
//*it = dereference and gets the value
//++it = move to the next element
// it != end = check if finished
//it is used because not all containrs work the same


    //void addNumber(std::vector<int> v) = will work only to add vector, not on list or deque
    //templates MUST be fully declared in the header file
    //because it is writing a definition
    //if written in cpp, other cpp (main) cannot see it
    template <typename T>
    void addNumber(T begin, T end)
    {
        unsigned int sizeToAdd = std::distance(begin, end);
        if (container.size() + sizeToAdd > N)
            throw std::runtime_error("Error: No space to add numbers\n");
        container.insert(container.end(), begin, end);
    }

};

#endif