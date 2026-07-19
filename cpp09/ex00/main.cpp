#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: ./btc input_file." << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange map;
        map.buildMap();
        map.readInput(argv[1]);
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    return (0);
}