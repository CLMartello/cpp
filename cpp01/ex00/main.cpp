
#include "Zombie.hpp"

int main(void) {
    //if Zombie x(name) -> auto-create and auto-destroy in stack memory
    //newZombie(name) -> allocate, create in heap memory, need delete to free memory allocated
    
    Zombie* heap_z = newZombie("Heap_Zombie_Dudu");
    randomChump("Stack_Zombie_Edu");

    heap_z->announce();
    delete heap_z;
    
    return (0);
}
