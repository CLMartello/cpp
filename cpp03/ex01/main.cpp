
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== CONSTRUCTION TEST ===\n";

    ClapTrap a("ClapA");
    ScavTrap b("ScavB");

    std::cout << "\n=== BASIC ATTACK TEST ===\n";

    a.attack("ScavB");
    b.attack("ClapA");

    std::cout << "\n=== DAMAGE TEST ===\n";

    b.takeDamage(30);
    b.takeDamage(50);

    std::cout << "\n=== REPAIR TEST ===\n";

    b.beRepaired(20);
    b.beRepaired(50);

    std::cout << "\n=== SPECIAL ABILITY TEST ===\n";

    b.guardGate();

    std::cout << "\n=== ENERGY DEPLETION TEST ===\n";

    for (int i = 0; i < 55; i++) {
        b.attack("dummy_target");
    }

    std::cout << "\n=== DEAD STATE TEST ===\n";

    b.takeDamage(200);      // force HP = 0
    b.attack("ClapA");      // should fail
    b.beRepaired(10);       // should fail

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===\n";

    ScavTrap c(b);          // copy constructor
    c.guardGate();
    c.attack("test");

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===\n";

    ScavTrap d;
    d = c;                  // assignment operator
    d.attack("after_assign");


    std::cout << "\n=== END OF PROGRAM ===\n";

    return 0;
}