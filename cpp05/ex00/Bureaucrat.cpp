#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : Bureaucrat("Lowbie", 150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name),
      grade(checkGrade(other.grade))
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other) {
        checkGrade(grade = other.grade);
    }
    return *this;
}

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
    : std::runtime_error("grade too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("grade too low")
{
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
    int grade = bureaucrat.getGrade();
    const std::string& name = bureaucrat.getName();
    return stream << name << ", bureaucrat grade " << grade << ".\n";
}
