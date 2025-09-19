#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade is too high!";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade is too low!";
            }
    };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
