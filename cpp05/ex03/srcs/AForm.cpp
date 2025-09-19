#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& n, int s, int e)
    : name(n), isSigned(false), signGrade(s), execGrade(e) {
    if (s < 1 || e < 1)
        throw GradeTooHighException();
    if (s > 150 || e > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::checkExecution(Bureaucrat const & executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > execGrade)
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);
    action();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName()
       << " [Sign grade: " << f.getSignGrade()
       << ", Exec grade: " << f.getExecGrade()
       << ", Signed: " << (f.getIsSigned() ? "yes" : "no") << "]";
    return os;
}
