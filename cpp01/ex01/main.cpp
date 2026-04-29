
#include "Zombie.hpp"

int main(void) {
    int n = 3;
    Zombie *horde  = zombieHorde(n, "Alejandro");
    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
