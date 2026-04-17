
#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int     index;
    int     total;
public:
    PhoneBook();
    void add_Contact();
    void search_Contact() const;
};

#endif
