
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "Default constructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
// : ClapTrap() in the function is only used in constructors

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    std::cout << "ScavTrap copy assignment called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoint <= 0 || _energyPoint <= 0) {
        std::cout << "ScavTrap " << _name << " cannot attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " 
              << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoint--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name
              << " is in Gate keeper mode" << std::endl; 
}

