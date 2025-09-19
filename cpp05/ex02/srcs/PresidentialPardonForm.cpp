#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& t)
    : AForm("PresidentialPardon", 25, 5), target(t) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
