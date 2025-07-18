#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int count = 5;
    Zombie* horde = zombieHorde(count, "HordeZombie");

    if (horde) {
        for (int i = 0; i < count; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }
    return 0;
}
