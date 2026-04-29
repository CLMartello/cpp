
#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie( std::string name ) {
    _name = name;
}
//function constructor using in creation

// Zombie::Zombie (std::string name) : _name(name) {};

Zombie::~Zombie( void ) {
    std::cout <<_name << " is dead" <<std::endl;
}

void    Zombie::announce( void ) {
    std::cout << _name
              << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName( std::string name ) {
    _name = name;
}
//function used after creation, to modify object that already exists
//necessary because of use of new Zombie[N]
//new Zombie[N] does not use Zombie(std::string name), it uses the default constructor no parameters


