#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Form taxForm("TaxForm", 45, 100);

        std::cout << taxForm << std::endl;

        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat boss("Boss", 40);
        boss.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
