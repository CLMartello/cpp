#ifndef CONTACT_HPP

#define CONTACT_HPP

#include <string>
//<string> allows to use std::string

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
public:
	Contact(); //constructor
	//public are the functions to interact with the class
	void setContact(); //setter
	//const is used to indicate that the function does not modify the object
	//as the functions display only show, they show not modify
	//getter
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
