#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>
#include <exception>
#include <fstream>
#include <cfloat>

class BitcoinExchange
{
private:
    std::map<std::string, float> _map;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);

    void buildMap();
    void readInput(std::string filename);
    float getRate(std::string date);
};

#endif