
#ifndef DIAMONDTRAP_HPP

#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap &operator=(const DiamondTrap &copy);
    ~DiamondTrap();

    void attack(const std::string& target);
    //needs to redefine in diamond to avoid ambiguity (call both scav and frag attacks)
    //and will allow to call fragtrap attack later
    void whoAmI();

};

#endif