#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& copy);
}

#endif