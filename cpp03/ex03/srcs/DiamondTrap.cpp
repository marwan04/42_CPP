#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    name = "Unnamed";
    ClapTrap::name = name + "_clap_name";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& n)
{
    name = n;
    ClapTrap::name = n + "_clap_name";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : FragTrap(other), ScavTrap(other)
    {
        name = other.name;
        ClapTrap::name = other.ClapTrap::name;
        std::cout << "DiamondTrap copy constructor called!" << std::endl;
    }

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
    name = other.name;
    ClapTrap::name = other.ClapTrap::name;
    std::cout << "DiamondTrap assignment operator called!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
