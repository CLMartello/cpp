#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

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
    std::vector<int> mergeInsertVec(std::vector<int> vec);
    std::deque<int> mergeInsertDeq(std::deque<int> deq);
};

#endif