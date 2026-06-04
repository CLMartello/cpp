
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "Default constructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}
// : ClapTrap() in the function is only used in constructors

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    std::cout << "FragTrap copy assignment called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap requests a positive high five" << std::endl;
}

void FragTrap::getStats() const {
    std::cout << _hitPoint << std::endl;
    std::cout << _energyPoint << std::endl;
    std::cout << _attackDamage << std::endl;
}
