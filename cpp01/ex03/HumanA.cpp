
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {}
    //class members are constructed before entering the constructor
    //must initilize weapon before entering HumanA constructor

void    HumanA::attack() const {
    std::cout << _name 
              << " attacks with their "
              << _weapon.getType() << std::endl;
}