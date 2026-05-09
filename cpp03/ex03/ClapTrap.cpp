
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;

}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap " << this->_name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : _name(copy._name),
      _hitPoint(copy._hitPoint),
      _energyPoint(copy._energyPoint),
      _attackDamage(copy._attackDamage) {  
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "ClapTrap copy assignment called" << std::endl;
    if (this != &copy) {
        this->_name = copy._name;
        this->_hitPoint = copy._hitPoint;
        this->_energyPoint = copy._energyPoint;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoint <= 0 || _energyPoint <= 0) {
        std::cout << "ClapTrap " << _name << " cannot attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " 
              << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoint -= amount;
    if (_hitPoint < 0)
        _hitPoint = 0;
    std::cout << "ClapTrap " << _name << " loses " << amount
              << " points of HP! HP = " << _hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoint <= 0 || _energyPoint <= 0) {
        std::cout << "ClapTrap " << _name << " cannot repair" << std::endl;
        return;
    }
    _hitPoint += amount;
    _energyPoint--;
    std::cout << "ClapTrap " << _name << " repairs "
              << amount << " points of HP! HP = "
              << _hitPoint << std::endl;
}

