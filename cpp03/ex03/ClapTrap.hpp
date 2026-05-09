
#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap {
protected:
    std::string _name;
    int         _hitPoint;
    int         _energyPoint;
    int         _attackDamage;


public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &copy);
    virtual ~ClapTrap();
    //if a class have any virtual function, it must have a virtual destructor
    //needs a virtual destructor so derived objects are destroyed in right order
    //if not virtual, it is not going to call ~ScavTrap, and will skip it - memory leak
    //virtual makes ~ScavTrap, then ~ClapTrap

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif
