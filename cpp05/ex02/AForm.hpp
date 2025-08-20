#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm
{
public:
    AForm() = delete;
    virtual ~AForm() = default;

    const std::string& getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getSigned() const;

    void beSigned(const Bureaucrat& signer);
    virtual void execute(const Bureaucrat& executor) const = 0;

    struct GradeTooHighException: public std::runtime_error
    {
        GradeTooHighException();
    };

    struct GradeTooLowException: public std::runtime_error
    {
        GradeTooLowException();
    };

protected:
    AForm(const AForm&) = default;
    AForm& operator=(const AForm&) = delete;
    AForm(const std::string& name, int signGrade, int execGrade);
    static int checkGrade(int grade);
    void checkRequirements(const Bureaucrat& executor) const;

private:
    const std::string name;
    const int signGrade;
    const int execGrade;
    bool isSigned;
};

std::ostream& operator<<(std::ostream& stream, const AForm& form);
