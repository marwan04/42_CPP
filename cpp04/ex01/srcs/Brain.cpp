#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, const std::string& idea)
{
    if (i >= 0 && i < 100)
        ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100)
        return ideas[i];
    return "";
}
