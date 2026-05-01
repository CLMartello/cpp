
#include "Harl.hpp"

void    Harl::debug( void ) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void    Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::complain( std::string level ) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    //*functions is a pointer to a member function (a function inside a class)

    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            (this->*functions[i])();
            //this points to the current object, in this case, Harl
            //can be this->variable
            //this->function()
            //-> normal member and ->* member pointer
            //(this->-*f[i]()); is the same as this->debug();
            //if only *f[i](); there is no object being called, so this is about the object

            //functions[i] = which function
            //this = which object
            // ->* bind the object to the function
            // (); execute function

            //MEMBER POINTER is a pointer to something INSIDE A CLASS
            //data member or member function, data and function inside class
            //diferent because the function needs the object to exists
            //so it needs to call the object before call the function
            
    }
}