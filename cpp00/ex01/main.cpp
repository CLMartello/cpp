
#include "PhoneBook.hpp"
#include <iostream>

//#include "Contact.hpp"
// int    main() {
//     Contact ct;
//     ct.setContact();
//     ct.display_Contact();
//     return 0;
// }

int main() {
    PhoneBook pb;
    std::string command;

    while (1) {
        std::cout << "Enter one command: ADD, SEARCH, EXIT: ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "ADD")
            pb.addContact();
        else if (command == "SEARCH")
            pb.searchContact();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Unkown command." << std::endl;
    }
    return (0);
}