
#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _map(copy._map) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
    if (this != &copy)
    {
        this->_map = copy._map;
    }
    return (*this);
}

void BitcoinExchange::buildMap()
{
    std::ifstream file;

    file.open("data.csv");
    if (!file)
        throw std::runtime_error("Error: could not open csv data file.\n");
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string strvalue;

        if (!std::getline(ss, date, ',')) //getline until the comma, removes comma
            throw std::runtime_error("Error: bad input => csv date\n");
        if (!std::getline(ss, strvalue)) //getline of what was left in line
            throw std::runtime_error("Error: bad input => csv line size\n");

        std::stringstream ssvalue(strvalue);
        float value;
        ssvalue >> value;

        if (ssvalue.fail())
            throw std::runtime_error("Error: bad input => csv float\n");

        _map[date]=value;  
    }
    file.close();
}

static bool valiDate(std::string date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    int year, month, day;

    std::stringstream(date.substr(0, 4)) >> year;
    std::stringstream(date.substr(5, 2)) >> month;
    std::stringstream(date.substr(8, 2)) >> day;

    if (year < 1970 || year > 2026)
        return (false);

    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return (day >= 1 && day <= 31);
        
        case 4: case 6: case 9: case 11:
            return (day >=1 && day <= 30);

        case 2:
            return (day >= 1 && day <= (leapYear ? 29 : 28));

        default:
            return (false);
    }
}

float    BitcoinExchange::getRate(std::string date)
{
    std::map<std::string, float>::const_iterator it = _map.lower_bound(date);
    //lower_bound return first element that is >= to date

    if (it != _map.end() && it->first == date)
        return (it->second);

    if (it == _map.begin())
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (-1);
    }
    --it;
    return (it->second);
}

void BitcoinExchange::readInput(std::string filename)
{
    std::ifstream file;

    file.open(filename.c_str());
    if (!file)
        throw std::runtime_error("Error: could not open input file.\n");
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string strvalue;

        if (!std::getline(ss, date, '|') || !std::getline(ss, strvalue))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;            
        }

        //trim spaces
        date.erase(date.size() - 1);
        strvalue.erase(0, 1);

        std::stringstream ssvalue(strvalue);
        float value;
        ssvalue >> value;

        if (!valiDate(date))
        {
            std::cout << "Error: bad date => " << line << std::endl;
            continue;
        }           
        if (ssvalue.fail())
        {
            std::cout << "Error: bad input => " << strvalue << std::endl;
            continue;
        }
        if (value < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if (value > 1000)
            std::cout << "Error: too large a number." << std::endl;
        else
        {

            float rate = getRate(date);
            if (rate != -1)
            {
                std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
            }
        }
    }
    file.close();
}