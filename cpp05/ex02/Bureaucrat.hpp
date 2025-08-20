#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat
{
public:
    Bureaucrat() = default;
    ~Bureaucrat() = default;
    Bureaucrat(const Bureaucrat&) = default;
    Bureaucrat& operator=(const Bureaucrat&) = delete;
    Bureaucrat(const std::string& name, int grade);

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form) const;
    void executeForm(AForm& form) const;

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

    const std::string name = "Anonymous";
    int grade = 150;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);
