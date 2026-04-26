
#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    return (new Zombie(name));
    //new function = allocate heap memory and construct the object
    //give me enough memory to llocate Zombie object
    //can constructor Zombie to construct the object
    //and then return the object allocated and created
}
