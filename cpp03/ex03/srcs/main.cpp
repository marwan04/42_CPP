#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt("Diamondy");

    dt.attack("Dragon");
    dt.takeDamage(40);
    dt.beRepaired(30);
    dt.whoAmI();

    DiamondTrap copy(dt);
    copy.whoAmI();

    DiamondTrap assign;
    assign = dt;
    assign.whoAmI();

    return 0;
}
