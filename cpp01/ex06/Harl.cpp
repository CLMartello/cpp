
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

    //switch is a clean way to replace many if and else
    //switch (x) { case 0: ... case 1: ... case 2: ... }
    //if switch value == 1, start executing on case 1, and so on
    //switch will continue from the start to finish, unless there is a break; in the case
    //fallthrough is when a switch does not have a break
    //code [[fallthrough]] is telling compiler the continue of executing is intentional
    //default: is the equivalent to else
   
    int index = -1;

    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            index = i;
    }

    switch(index) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
            std::cout << std::endl;
        case 1: 
            std::cout << "[ INFO ]" << std::endl;
            info();
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            warning();
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}