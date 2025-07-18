#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    type = other.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "*Animal noise*" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
