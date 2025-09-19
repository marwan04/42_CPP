#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    class GradeTooHighException : public std::exception {
        public: const char* what() const throw() { return "Form grade is too high!"; }
    };
    class GradeTooLowException : public std::exception {
        public: const char* what() const throw() { return "Form grade is too low!"; }
    };
    class FormNotSignedException : public std::exception {
        public: const char* what() const throw() { return "Form is not signed!"; }
    };

    AForm(const std::string& name, int s, int e);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);

    void execute(Bureaucrat const & executor) const;
    virtual void action() const = 0;

protected:
    void checkExecution(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
