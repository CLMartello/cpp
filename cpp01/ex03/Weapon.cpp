
#include "Weapon.hpp"
#include <iostream>

// Weapon::Weapon(std::string type) {
//     _type = type;
// }
//work like this too, but is not proper cpp

Weapon::Weapon(std::string type) : _type(type) {}
//this way construct already with value inside

const std::string Weapon::getType(void) const {
    return (_type);
}

void    Weapon::setType(std::string type) {
    _type = type;
}