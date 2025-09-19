#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw() {
                return "Form grade is too high!";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {
                return "Form grade is too low!";
            }
    };

    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
