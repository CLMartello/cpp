
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"),
      _name("Default")
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 30;
    std::cout << "Default constructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      _name(name)
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy),
      ScavTrap(copy),
      FragTrap(copy)
{
    this->_name = copy._name;
    this->_hitPoint = copy._hitPoint;
    this->_energyPoint = copy._energyPoint;
    this->_attackDamage = copy._attackDamage;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
    std::cout << "DiamondTrap copy assignment called" << std::endl;
    if (this != &copy) {
        ClapTrap::operator=(copy);
        _name = copy._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

void DiamondTrap::getStats() const {
    std::cout << _hitPoint << std::endl;
    std::cout << _energyPoint << std::endl;
    std::cout << _attackDamage << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << " and my father is ClapTrap "
              << ClapTrap::_name << std::endl;
}