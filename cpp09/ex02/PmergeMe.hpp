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
    std::vector<int> _vecN;
    std::deque<int> _deqN;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    void parseInput(int size, char **input);
    void mergeInsertionSort();
    void mergeVec();
    void mergeDeq();
};

#endif