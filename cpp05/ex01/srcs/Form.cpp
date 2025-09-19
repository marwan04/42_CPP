#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& n, int s, int e)
    : name(n), isSigned(false), signGrade(s), execGrade(e) {
    if (s < 1 || e < 1)
        throw GradeTooHighException();
    if (s > 150 || e > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName()
       << " [Sign grade: " << f.getSignGrade()
       << ", Exec grade: " << f.getExecGrade()
       << ", Signed: " << (f.getIsSigned() ? "yes" : "no") << "]";
    return os;
}
