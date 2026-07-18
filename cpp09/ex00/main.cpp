#include "BitcoinExchange.hpp"

int checkDate(std::string date)
{
    if (date[4] != '-' && date[7] != '-')
        return (1);
    for (size_t i = 0; i < 4; ++i)
        if (!isdigit(date[i]))
            return(1);
    for (size_t i = 5; i < 7; ++i)
        if (!isdigit(date[i]))
            return (1);
    for (size_t i = 8; i < 10; ++i)
        if (!isdigit(date[i]))
            return (1);
    return (0); 
}

int checkValue(std::string strvalue)
{
    if (strvalue.empty())
        return (1);
    int dot = 0;
    for (size_t i = 0; i < strvalue.length() -1; ++i)
    {
        if (strvalue[i] == '.')
        {
            dot += 1;
            if (dot > 1)
                throw std::runtime_error("Error: value has more than one dot\n");
        }
        if (!isdigit(strvalue[i]) && strvalue[i] != '.')
            throw std::runtime_error("Error: value is not a digit\n");
    }
    return (0);
}

void    readCsv()
{
    std::ifstream file; //input file stream

    file.open("data.csv");
    if (!file)
        throw std::runtime_error("Error: problem opening csv file\n");
    std::map<std::string, float> data;
    std::string str;
    getline(file, str); //skip header
    
    while (getline(file, str))
    {
        if (str[10] != ',' || str.length() < 12)
            throw std::runtime_error("Error: csv file without comma or too small\n");
        std::string date = str.substr(0, 10);
        if (checkDate(date) == 1)
            throw std::runtime_error("Error: problem in date of csv file\n");
        std::string strvalue = str.substr(11, str.length());
        if (checkValue(strvalue) == 1)
            throw std::runtime_error("Error: problem in value of csv file\n");
        std::stringstream ss(strvalue);
        float value;
        ss >> value;
        data[date]=value;
    }
    file.close();
}

void    readInput(std::string input)
{
    std::ifstream file;

    file.open(input);
    if (!file)
        throw std::runtime_error("Error: problem opening input file\n");
    std::map<std::string, float> input;
    std::string str;
    getline(file, str); //skip header
    
    while (getline(file, str))
    {
        if (str[11] != '|' || str.length() < 14)
            throw std::runtime_error("Error: input file without pipe or too small\n");
        std::string date = str.substr(0, 10);
        if (checkDate(date) == 1)
            std::cout << "Error: bad input => " << date << std::endl;
        std::string strvalue = str.substr(11, str.length());
        if (checkValue(strvalue) == 1)
            throw std::runtime_error("Error: problem in value of csv file\n");
        std::stringstream ss(strvalue);
        float value;
        ss >> value;
        data[date]=value;
    }
    file.close();
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Error: need input file." << std::endl;
        return (1);
    }
    else if (argc != 2)
    {
        std::cout << "Error: ./btc input_file." << std::endl;
        return (1);
    }
    (void)argv;
    readCsv();
    readInput(argv[1]);

    //input files: input and csv
    
    //choose container -> map?

    //parse csv
    //parse input


}