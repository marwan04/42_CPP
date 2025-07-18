#include "Character.hpp"
#include <iostream>

Character::Character() : name("")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name)
{
    std::cout << "Character name constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(Character const & src) : name(src.name)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (src.inventory[i])
            this->inventory[i] = src.inventory[i]->clone();
    }
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

Character & Character::operator=(Character const & rhs)
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
            {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (rhs.inventory[i])
                this->inventory[i] = rhs.inventory[i]->clone();
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (!m) {
        std::cout << "Cannot equip NULL materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            std::cout << this->name << " equipped " << m->getType() << " to slot " << i << std::endl;
            return;
        }
    }
    std::cout << this->name << " cannot equip " << m->getType() << " because inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory slot: " << idx << std::endl;
        return;
    }
    
    if (!this->inventory[idx]) {
        std::cout << "No materia in slot " << idx << " to unequip" << std::endl;
        return;
    }
    
    std::cout << this->name << " unequipped " << this->inventory[idx]->getType() << " from slot " << idx << std::endl;
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory slot: " << idx << std::endl;
        return;
    }
    
    if (!this->inventory[idx]) {
        std::cout << "No materia in slot " << idx << " to use" << std::endl;
        return;
    }
    
    this->inventory[idx]->use(target);
}
