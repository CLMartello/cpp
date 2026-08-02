
#include "PmergeMe.hpp"

// - Orthodox Canonical Form 

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) :
    _vecN(other._vecN),
    _deqN(other._deqN)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vecN = other._vecN;
        this->_deqN = other._deqN;
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
        _vecN.push_back(n);
        _deqN.push_back(n);
    }
}

void PmergeMe::mergeInsertionSort()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vecN.size(); i++)
        std::cout << _vecN[i] << " ";
    std::cout << std::endl;

    double vecTime = 0;
    double deqTime = 0;

    if (_vecN.size() > 1)
    {
        struct timespec start, end;

        clock_gettime(CLOCK_MONOTONIC, &start);
        _vecN = mergeInsertVec(_vecN);
        clock_gettime(CLOCK_MONOTONIC, &end);
        vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

        clock_gettime(CLOCK_MONOTONIC, &start);
        _deqN = mergeInsertDeq(_deqN);
        clock_gettime(CLOCK_MONOTONIC, &end);
        deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

    }

        std::cout << "After: ";
    for (size_t i = 0; i < _vecN.size(); i++)
        std::cout << _vecN[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of "
        << _vecN.size() << " elements with std::vector : "
        << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " 
        << _deqN.size() << " elements with std::deque : "
        << deqTime << " us" << std::endl;

}

// - Vector Functions

static void insertVec(std::vector<int>& vec, int value, size_t pos)
{
    std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.begin() + pos, value);
    vec.insert(it, value);
}

static std::vector<size_t> jacobsthalVec(size_t size)
{
    std::vector<size_t> jacobVec;
    jacobVec.push_back(1);
    if (size == 1)
        return (jacobVec);

    size_t prev = 1;
    size_t curr = 3;
    size_t next;
    size_t reverse;
    while (curr < size)
    {
        jacobVec.push_back(curr);
        next = 2 * prev + curr;
        reverse = curr - 1;
        while (reverse > prev)
            jacobVec.push_back(reverse--);
        prev = curr;
        curr = next;
    }
    reverse = size;
    while (reverse > prev)
        jacobVec.push_back(reverse--);
    return (jacobVec);
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> vec)
{
    if (vec.size() <= 1)
        return (vec);

    int leftover = -1;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
        {
            int first = vec[i];
            int second = vec[i + 1];
            if (first > second)
                std::swap(first, second);

            pairs.push_back(std::make_pair(first, second));
        }
        else
            leftover = vec[i];
    }

    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)  
        mainChain.push_back(pairs[j].second);

    mainChain = mergeInsertVec(mainChain);
    
    std::vector<size_t> jacobVec = jacobsthalVec(pairs.size());
    for (size_t k = 0; k < jacobVec.size(); ++k)
    {
        size_t index = jacobVec[k] - 1;
        size_t pos = std::find(mainChain.begin(), mainChain.end(), pairs[index].second) - mainChain.begin();
        insertVec(mainChain, pairs[index].first, pos);
    }

    if (leftover != -1)
        insertVec(mainChain, leftover, mainChain.size());

    return (mainChain);
}

// - Deque Functions

static void insertDeq(std::deque<int>& deq, int value, size_t pos)
{
    std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.begin() + pos, value);
    deq.insert(it, value);
}

static std::deque<size_t> jacobsthalDeq(size_t size)
{
    std::deque<size_t> jacobDeq;
    jacobDeq.push_back(1);
    if (size == 1)
        return (jacobDeq);

    size_t prev = 1;
    size_t curr = 3;
    size_t next;
    size_t reverse;
    while (curr < size)
    {
        jacobDeq.push_back(curr);
        next = 2 * prev + curr;
        reverse = curr - 1;
        while (reverse > prev)
            jacobDeq.push_back(reverse--);
        prev = curr;
        curr = next;
    }
    reverse = size;
    while (reverse > prev)
        jacobDeq.push_back(reverse--);
    return (jacobDeq);
}

std::deque<int> PmergeMe::mergeInsertDeq(std::deque<int> deq)
{
    if (deq.size() <= 1)
        return (deq);

    int leftover = -1;
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < deq.size(); i += 2)
    {
        if (i + 1 < deq.size())
        {
            int first = deq[i];
            int second = deq[i + 1];
            if (first > second)
                std::swap(first, second);

            pairs.push_back(std::make_pair(first, second));
        }
        else
            leftover = deq[i];
    }

    std::deque<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].second);

    mainChain = mergeInsertDeq(mainChain);

    std::deque<size_t> jacobDeq = jacobsthalDeq(pairs.size());
    for (size_t k = 0; k < jacobDeq.size(); ++k)
    {
        size_t index = jacobDeq[k] - 1;
        size_t pos = std::find(mainChain.begin(), mainChain.end(), pairs[index].second) - mainChain.begin();
        insertDeq(mainChain, pairs[index].first, pos);
    }

    if (leftover != -1)
        insertDeq(mainChain, leftover, mainChain.size());

    return (mainChain);
}


