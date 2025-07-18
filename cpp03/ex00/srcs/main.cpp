#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("John");

    bot.attack("Target A");
    bot.takeDamage(4);
    bot.beRepaired(3);

    ClapTrap clone(bot);
    clone.attack("Target B");

    ClapTrap assigned;
    assigned = bot;
    assigned.takeDamage(6);
    assigned.beRepaired(2);

    return 0;
}
