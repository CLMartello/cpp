
#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Alpha");
    std::cout << std::endl;
    ClapTrap b("Beta");

    std::cout << "\n--- Attack test ---\n";
    a.attack("Beta");
    b.attack("Alpha");

    std::cout << "\n--- Damage test ---\n";
    b.takeDamage(5);

    std::cout << "\n--- Repair test ---\n";
    b.beRepaired(3);

    std::cout << "\n--- Energy depletion test ---\n";
    for (int i = 0; i < 11; i++) {
        a.attack("Beta");
    }

    std::cout << "\n--- Death test ---\n";
    b.takeDamage(100);
    b.attack("Alpha");     // should not work
    b.beRepaired(10);      // should not work
    std::cout << std::endl;

    return 0;
}