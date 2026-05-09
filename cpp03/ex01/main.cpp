
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== CONSTRUCTION TEST ===\n";

    ClapTrap a("ClapA");
    std::cout << std::endl;
    ScavTrap b("ScavB");

    std::cout << "\n=== BASIC ATTACK TEST ===\n";

    a.attack("ScavB");
    b.attack("ClapA");

    std::cout << "\n=== DAMAGE TEST ===\n";

    a.takeDamage(5);
    b.takeDamage(30);

    std::cout << "\n=== REPAIR TEST ===\n";

    a.beRepaired(20);
    b.beRepaired(50);

    std::cout << "\n=== SPECIAL ABILITY TEST ===\n";

    b.guardGate();

    std::cout << "\n=== ENERGY DEPLETION TEST ===\n";

    for (int i = 0; i < 50; i++) {
        b.attack("dummy_target");
    }

    std::cout << "\n=== DEAD STATE TEST ===\n";

    b.takeDamage(200);      // force HP = 0
    b.attack("ClapA");      // should fail
    b.beRepaired(10);       // should fail

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===\n";

    ScavTrap c(b);          // copy constructor

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===\n";

    b = c;                  // assignment operator

    std::cout << "\n=== END OF PROGRAM ===\n";

    return 0;
}