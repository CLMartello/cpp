
#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::~Span() {}

Span::Span(const Span &copy) : N(copy.N)
{
    for (size_t i = 0; i < copy.container.size(); i++)
        this->container[i] = copy.container[i];
}

Span& Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->N = copy.N;
        for (size_t i = 0; i < copy.container.size(); i++)
            this->container[i] = copy.container[i];
    }
    return (*this);
}

void Span::addNumber(int num)
{
    if (container.size() < N)
    {
        container.push_back(num);
    }
    else
        throw std::runtime_error("Error: Container is full\n");
}

int Span::shortestSpan() const
{
    if(container.size() > 1)
    {
        int distance = INT_MAX;
        std::vector<int> sorted = container;
        std::sort(sorted.begin(), sorted.end());
        for (size_t i = 0; i < sorted.size() - 1; i++)
        {
            if (sorted[i + 1] - sorted[i] < distance)
                distance = sorted[i + 1] - sorted[i];
        }
        return (distance);
    }
    else
        throw std::runtime_error("Too small size to calculate span of container\n");
}

int Span::longestSpan() const
{
    if(container.size() > 1)
    {
        int min = *std::min_element(container.begin(), container.end());
        int max = *std::max_element(container.begin(), container.end());
        return ((max - min));
    }
    else
        throw std::runtime_error("Too small size to calculate span of container\n");
}