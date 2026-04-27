
#include "Zombie.hpp"

int main(void) {
    Zombie *horde  = zombieHorde(3, "Alejandro");
    delete[] horde;
    return (0);
}
