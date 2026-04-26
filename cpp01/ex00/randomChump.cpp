
#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie z = Zombie(name);
    //here we are allocating in stack memory
    //and it will be auto-destroyed after end of program

    z.announce();
}
