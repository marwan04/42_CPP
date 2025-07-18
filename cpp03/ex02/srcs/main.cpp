#include "FragTrap.hpp"

int main()
{
    FragTrap frag("Bob");

    frag.attack("Enemy1");
    frag.takeDamage(40);
    frag.beRepaired(25);
    frag.highFivesGuys();

    FragTrap copyFrag(frag);
    copyFrag.attack("Enemy2");

    FragTrap assignFrag;
    assignFrag = frag;
    assignFrag.highFivesGuys();

    return 0;
}
