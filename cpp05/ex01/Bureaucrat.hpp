#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat&);
    Bureaucrat& operator=(const Bureaucrat&) = delete;
    Bureaucrat(const std::string& name, int grade);

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form) const;

    struct GradeTooHighException: public std::runtime_error
    {
        GradeTooHighException();
    };

    struct GradeTooLowException: public std::runtime_error
    {
        GradeTooLowException();
    };

private:
    static int checkGrade(int grade);

    const std::string name;
    int grade;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);
