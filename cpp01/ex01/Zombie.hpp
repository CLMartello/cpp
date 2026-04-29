
#ifndef ZOMBIE_H

#define ZOMBIE_H

#include <string>
#include <iostream>

class   Zombie {
private:
    std::string _name;

public:
    Zombie(); //default constructor
              //only works for new Zombie[] because in array have no parameters
    Zombie(std::string name); //parameterized constructor
    ~Zombie(); //destructor
    
    void    announce(void);
    void    setName(std::string name);

};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif
