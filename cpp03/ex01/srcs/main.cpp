#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Serena");

    scav.attack("Target X");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    ScavTrap clone(scav);
    clone.attack("Target Y");

    ScavTrap assigned;
    assigned = scav;
    assigned.guardGate();

    return 0;
}
