
#include "PhoneBook.hpp"
#include <iostream>

//#include "Contact.hpp"
// int    main() {
//     Contact ct;
//     ct.set_Contact();
//     ct.display_Contact();
//     return 0;
// }

int main() {
    PhoneBook pb;
    std::string command;

    while (1) {
        std::cout << "Enter one command: ADD, SEARCH, EXIT: ";
        std::getline(std::cin, command);

        if (command == "ADD")
            pb.add_Contact();
        else if (command == "SEARCH")
            pb.search_Contact();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Unkown command." << std::endl;
    }
    return (0);
}