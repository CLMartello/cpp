
#include "../include/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

//constructor
Contact::Contact() {}

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

std::string Contact::getFirstName() const {
    return (first_name);
}

std::string Contact::getLastName() const {
    return (last_name);
}

std::string Contact::getNickname() const {
    return (nickname);
}

std::string Contact::getPhoneNumber() const {
    return (phone_number);
}

std::string Contact::getDarkestSecret() const {
    return (darkest_secret);
}

void    Contact::setContact() {
    first_name = getInput("Insert first name of Contact: ");
    last_name = getInput("Insert last name of Contact: ");
    nickname = getInput("Insert nickname of Contact: ");
    phone_number = getInput("Insert phone number: ");
    darkest_secret = getInput("Insert darkest secret: ");
}



