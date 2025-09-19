#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        boss.executeForm(shrub);

        intern.signForm(shrub);
        boss.signForm(shrub);
        boss.signForm(robo);
        boss.signForm(pardon);

        boss.executeForm(shrub);
        boss.executeForm(robo);
        boss.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
