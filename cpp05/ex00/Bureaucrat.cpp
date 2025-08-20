#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name),
      grade(checkGrade(grade))
{
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    checkGrade(--grade);
}

void Bureaucrat::decrementGrade()
{
    checkGrade(++grade);
}

int Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("grade is too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("grade is too low")
{
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
    int grade = bureaucrat.getGrade();
    const std::string& name = bureaucrat.getName();
    return stream << name << ", bureaucrat grade " << grade;
}
