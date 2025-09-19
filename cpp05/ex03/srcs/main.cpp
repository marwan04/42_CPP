#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "-----" << std::endl;

    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        Bureaucrat worker("Worker", 130);
        worker.signForm(*form);
        worker.executeForm(*form);
        delete form;
    }

    std::cout << "-----" << std::endl;

    form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "-----" << std::endl;

    form = someRandomIntern.makeForm("coffee order", "Bob");
    if (form) delete form;

    return 0;
}
