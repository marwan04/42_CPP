#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (src.templates[i])
            this->templates[i] = src.templates[i]->clone();
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i])
            delete this->templates[i];
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->templates[i])
            {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (rhs.templates[i])
                this->templates[i] = rhs.templates[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
    {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!this->templates[i])
        {
            this->templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << " materia" << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource cannot learn more materias, memory is full" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i] && this->templates[i]->getType() == type)
        {
            std::cout << "MateriaSource created " << type << " materia" << std::endl;
            return this->templates[i]->clone();
        }
    }
    std::cout << "MateriaSource cannot create unknown type: " << type << std::endl;
    return NULL;
}