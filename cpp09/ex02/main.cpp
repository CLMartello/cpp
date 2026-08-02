
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "./PmergeMe NUMBERS" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe sequence;
        sequence.parseInput(argc, argv);
        sequence.mergeInsertionSort();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    return (0);
}