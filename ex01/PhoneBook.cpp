
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(): index(0), total(0) {}
//constructor of PhoneBook class
//runs automatically when creates a PhoneBook
//index(0) and total(0) -> initializer list, values to initializes PhoneBook


void    PhoneBook::add_Contact() {
    contacts[index].set_Contact();
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



void    PhoneBook::search_Contact() const {
    if (total == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for (int i = 0; i < total; i++)
        contacts[i].display_all_Contacts(i);
    std::cout << "Enter index of Contact: ";
    std::string input;
    std::getline(std::cin, input);
    int index = std::atoi(input.c_str());
    if (input.empty() || std::isalpha(index) || index < 0 || index >= total)
        std::cout << "Invalid index." << std::endl;
    else
        contacts[index].display_one_Contact();
}