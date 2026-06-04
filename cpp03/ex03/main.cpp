#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

    std::cout << "\n=== CONSTRUCTION TEST ===\n";

    ClapTrap a("ClapA");
    std::cout << std::endl;
    ScavTrap b("ScavB");
    std::cout << std::endl;
    FragTrap c("FragC");
    c.getStats();
    std::cout << std::endl;
    DiamondTrap d("DiamondD");
    d.getStats();

    std::cout << "\n=== BASIC ATTACK TEST ===\n";

    a.attack("enemy1");
    b.attack("enemy2");
    c.attack("enemy3");
    d.attack("enemy4");

    std::cout << "\n=== DAMAGE / REPAIR TEST ===\n";

    d.takeDamage(40);
    d.beRepaired(20);

    std::cout << "\n=== SPECIAL ABILITIES TEST ===\n";

    b.guardGate();
    std::cout << std::endl;
    c.highFivesGuys();
    std::cout << std::endl;
    d.whoAmI();

    std::cout << "\n=== ENERGY DEPLETION TEST ===\n";

    for (int i = 0; i < 55; i++) {
        d.attack("dummy");
    }

    std::cout << "\n=== DEATH STATE TEST ===\n";

    d.takeDamage(500);
    std::cout << std::endl;
    d.attack("should_fail");
    d.beRepaired(10);

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===\n";

    DiamondTrap d2(d);

    std::cout << "\n=== ASSIGNMENT TEST ===\n";

    d = d2;

    std::cout << "\n=== END OF PROGRAM ===\n";

    return 0;
}