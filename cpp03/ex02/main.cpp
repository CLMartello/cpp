
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== CONSTRUCTORS TEST ===\n";

    ClapTrap a("ClapA");
    ScavTrap b("ScavB");
    FragTrap c("FragC");

    std::cout << "\n=== ATTACK TEST ===\n";

    a.attack("target1");
    b.attack("target2");
    c.attack("target3");

    std::cout << "\n=== DAMAGE / REPAIR TEST ===\n";

    b.takeDamage(30);
    b.beRepaired(10);

    c.takeDamage(50);
    c.beRepaired(20);

    std::cout << "\n=== SPECIAL ABILITIES TEST ===\n";

    b.guardGate();
    c.highFivesGuys();

    std::cout << "\n=== ENERGY DEPLETION TEST ===\n";

    for (int i = 0; i < 55; i++) {
        c.attack("dummy");
    }

    std::cout << "\n=== DEATH STATE TEST ===\n";

    c.takeDamage(200);
    c.attack("should_not_work");
    c.beRepaired(10);

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===\n";

    FragTrap c2(c);
    c2.highFivesGuys();

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===\n";

    FragTrap c3;
    c3 = c2;
    c3.attack("after_assignment");

    std::cout << "\n=== END OF PROGRAM ===\n";

    return 0;
}