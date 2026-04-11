class Contact {
    char *first_name;
    char *last_name;
    int number;
    char *email;
}

class PhoneBook {
    public:
        int contacts[8];
        void ADD(class Contact);
        Contact SEARCH(class Contact);
        void EXIT(void);
}

void PhoneBook::ADD(class Contact) {
    add here;
}

class Contact   PhoneBook::SEARCH(class Contact) {
    search here;
}

void    PhoneBook::EXIT(void) {
    exit here;
}

int main() {
    PhoneBook agendinha;
    return 0;
}