
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook(): index(0), total(0) {}
//constructor of PhoneBook class
//runs automatically when creates a PhoneBook
//index(0) and total(0) -> initializer list, values to initializes PhoneBook


void    PhoneBook::addContact() {
    contacts[index].setContact();
    //needs a index because PhoneBook can only support 8 Contacts
    //if module of 8, when index is 8, it comes back to 0
    //that is circular indexing
    index = (index + 1) % 8;
    //index++;
    //if (index == 8)
    //    index = 0;   
    if (total < 8)
        total++;
    //total is the number of valid contacts stored
    //goes to 8 and then stop counting, because max is 8
}

static std::string formatw(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

static void    displayAllContacts(const Contact contact, int index) {
    std::cout << std::setw(10) << index << "|"
              << formatw(contact.getFirstName()) << "|"
              << formatw(contact.getLastName()) << "|"
              << formatw(contact.getNickname()) << std::endl;
}

void    PhoneBook::displayOneContact(int index) const {
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

static bool isNumber (std::string number) {
    for (int i = 0; number[i]; i++) {
        if (!std::isdigit(number[i])) {
            return (false);
        }
    }
    return (true);
}

void    PhoneBook::searchContact() const {
    if (total == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for (int i = 0; i < total; i++)
        displayAllContacts(contacts[i], i);
    std::cout << "Enter index of Contact: ";
    std::string input;
    std::getline(std::cin, input);
    int index = std::atoi(input.c_str());
    if (input.empty() || isNumber(input) == false || index < 0 || index >= total)
        std::cout << "Invalid index." << std::endl;
    else
        displayOneContact(index);
}