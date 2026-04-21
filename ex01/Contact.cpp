
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
//<iomanip> is to input and output manipulation, allows use string with define size
#include <string>
#include <cctype>
#include <cstdlib>


static std::string getInput(const std::string& prompt) {
    std::string input;

    while (1)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << "Input error." << std::endl;
            exit(1);
        }
        bool only_spaces = true;
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isspace(input[i]))
            {
                only_spaces = false;
                break ;
            }

        }
        if (input.empty() || only_spaces == true)
            std::cout << "Invalid input. Try again." << std::endl;
        else
            return (input);
    }
}

void    Contact::setContact() {
    first_name = getInput("Insert first name of Contact: ");
    last_name = getInput("Insert last name of Contact: ");
    nickname = getInput("Insert nickname of Contact: ");
    phone_number = getInput("Insert phone number: ");
    darkest_secret = getInput("Insert darkest secret: ");
}

static std::string formatw(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void    Contact::displayAllContacts(int index) const {
    std::cout << std::setw(10) << index << "|"
              << formatw(first_name) << "|"
              << formatw(last_name) << "|"
              << formatw(nickname) << std::endl;
}

void    Contact::displayOneContact() const {
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

