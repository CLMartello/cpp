
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- Constructors ---\n";
    ClapTrap a("Alpha");
    ScavTrap b("Guardian");

    std::cout << "\n--- Basic attacks ---\n";
    a.attack("Guardian");
    b.attack("Alpha");

    std::cout << "\n--- Damage & repair ---\n";
    b.takeDamage(30);
    b.beRepaired(10);

    std::cout << "\n--- Special ability ---\n";
    b.guardGate();

    std::cout << "\n--- Energy test ---\n";
    for (int i = 0; i < 55; i++) {
        b.attack("Target");
    }

    std::cout << "\n--- Death test ---\n";
    b.takeDamage(200);
    b.attack("Alpha");     // should not work
    b.beRepaired(50);      // should not work

    std::cout << "\n--- Copy test ---\n";
    ScavTrap c(b);         // copy constructor
    ScavTrap d;
    d = b;                 // copy assignment

    std::cout << "\n--- End of program ---\n";
    return 0;
}