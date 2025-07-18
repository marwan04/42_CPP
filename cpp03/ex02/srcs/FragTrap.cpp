#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
    this->name = name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called!" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "FragTrap " << name << " can't attack (no health or energy)!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " launches an epic strike on " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;
}
