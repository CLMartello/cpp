//constructor:
//function that runs automatically when create an object
//initialize object
//Constructor = make this object ready to use
//have to have same name as class

class Contact {
private:
	//std = from the standard library
	//::string = class string, represents a sequence of chars
	//std::string = handles memory and size alone, its more safe
	//:: = scope resolution operator, means where comething belongs
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public;
	Contact(); //default constructor
	display data;
}

class PhoneBook {
public:
        int contacts[8];
        void ADD(class Contact);
        Contact SEARCH(class Contact);
        void EXIT(void);
}

Contact::Contact() {
	std::cout << "Contact created" << std::endl;
}


void PhoneBook::ADD(class Contact);
class Contact   PhoneBook::SEARCH(class Contact);
void    PhoneBook::EXIT(void);


