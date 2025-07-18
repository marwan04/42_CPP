#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
{
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " can't attack (no health or energy)!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " ferociously attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
