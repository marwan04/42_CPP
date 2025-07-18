#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type("")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) : type(src.type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* AMateria has no effect on " << target.getName() << " *" << std::endl;
}
