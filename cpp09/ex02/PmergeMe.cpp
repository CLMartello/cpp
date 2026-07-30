
#include "PmergeMe.hpp"

// - Orthodox Canonical Form 

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) :
    vec(other.vec),
    pairs(other.pairs),
    deq(other.deq),
    hasLeftover(other.hasLeftover),
    leftover(other.leftover)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        this->pairs = other.pairs;
        this->deq = other.deq;
        this->hasLeftover = other.hasLeftover;
        this->leftover = other.leftover;
    }
    return (*this);
}

// - General Functions

void PmergeMe::parseInput(int size, char **input)
{
    for (int i = 1; i < size; i++)
    {
        std::string s(input[i]);
        if (s.empty())
            throw std::runtime_error("Error\n");
        for (size_t j = 0; j < s.length(); j++)
        {
            if (!isdigit(s[j]))
                throw std::runtime_error("Error\n");
        }
        long n = std::strtol(s.c_str(), NULL, 10);
        if (n < 0 || n > INT_MAX)
            throw std::runtime_error("Error\n");
        vec.push_back(n);
        deq.push_back(n);
    }
    std::cout << "Before :";
    for (int i = 1; i < size; i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
}

void startMergeInsert()
{
    //parse;
    //pairNumberVec;
    //vec all
    //print
}

// - Vector Functions

void PmergeMe::pairNumbersVec()
{
    if (vec.size() <= 1)
        return ;

    leftover = -1;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 >= vec.size())
            leftover = vec[i];

        int first = vec[i];
        int second = vec[i + 1];
        if (first < second)
            swap(first, second);

        pairs.push_back(std::make_pair(first, second));
    }   
}

void PmergeMe::pairNumbersDeq()
{
    if (deq.size() <= 1)
        return ;

    leftover = -1;
    for (size_t i = 0; i < deq.size(); i += 2)
    {
        if (i + 1 >= deq.size())
            leftover = deq[i];

        int first = deq[i];
        int second = deq[i + 1];
        if (first < second)
            swap(first, second);
        
        pairs.push_back(std::make_pair(first, second));
    }   
}

void mainChainVec()
{
    vec.clear();
    for (size_t i = 0; i < pairs.size(); i++)
        vec.push_back(pairs[i].first);

}

std::vector<int> PmergeMe::jacobsthalVec(size_t size)
{
    if (size == 0)
        return ;

    std::vector<int> jacobVec;
    jacobVec.push_back(1);
    if (size == 1)
        return (jacobVec);

    size_t prev = 1;
    size_t curr = 3;
    size_t next;
    while (curr < size)
    {
        jacobVec.push_back(curr);
        next = 2 * prev + curr;
        prev = curr;
        curr = next;
    }
    return (jacobVec);
}

std::vector<int> PmergeMe::jacobsthalDeq(size_t size)
{
    if (size == 0)
        return ;

    std::deque<int> jacobDeq;
    jacobDeq.push_back(1);
    if (size == 1)
        return (jacobDeq);

    size_t prev = 1;
    size_t curr = 3;
    size_t next;
    while (curr < size)
    {
        jacobDeq.push_back(curr);
        next = 2 * prev + curr;
        prev = curr;
        curr = next;
    }
    return (jacobDeq);
}

void PmergeMe::insert()
{

}

