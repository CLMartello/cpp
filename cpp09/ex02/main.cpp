
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
        sequence.printUnsorted();
        sequence.pairNumbers();
        sequence.winnersSort();
        sequence.insert();
        sequence.printSorted();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}