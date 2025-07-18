#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) 
    {
        std::cout << "ClapTrap " << name << " constructed!" << std::endl;
    }

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints), attackDamage(other.attackDamage)
    {
        std::cout << "ClapTrap copy constructor called!" << std::endl;
    }

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called!" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " can't attack (no health or energy)!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " can't repair (no health or energy)!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
}
