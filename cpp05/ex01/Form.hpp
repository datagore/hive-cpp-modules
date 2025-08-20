#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form
{
public:
    Form();
    ~Form() = default;
    Form(const Form&) = default;
    Form& operator=(const Form&) = delete;
    Form(const std::string& name, int signGrade, int execGrade);

    const std::string& getName() const;
    int getSignGrade() const;
    int getExecGrade() const;

    bool getSigned() const;
    void beSigned(const Bureaucrat& signer);

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
    const int signGrade;
    const int execGrade;
    bool isSigned;
};

std::ostream& operator<<(std::ostream& stream, const Form& form);
