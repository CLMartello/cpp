#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <climits>
#include <iostream>
#include <stdlib.h>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::vector<std::pair<int, int> > pairs;
    std::deque<int> deq;
    int leftover;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void parseInput(int size, char **input);
    void pairNumbersVec();
    void jacobsthal(size_t size);
    void insert();
};

#endif