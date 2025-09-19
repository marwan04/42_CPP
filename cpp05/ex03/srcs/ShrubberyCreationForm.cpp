#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
    : AForm("ShrubberyCreation", 145, 137), target(t) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs) return;
    ofs << "   ^   " << std::endl;
    ofs << "  /|\\  " << std::endl;
    ofs << " //|\\\\ " << std::endl;
    ofs << "   |   " << std::endl;
}
