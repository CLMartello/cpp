
#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap {
private:
    std::string _name;
    int         _hitPoint;
    int         _energyPoint;
    int         _attackDamage;


public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &copy);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif
