#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm& form) const
{
    try {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << "\n";
    } catch (const AForm::GradeTooLowException& exception) {
        std::cout << *this << " couldn't sign " << form;
        std::cout << " because " << exception.what() << "\n";
    }
}

void Bureaucrat::executeForm(const AForm& form)
{
    try {
        form.execute(*this);
        std::cout << *this << " executed " << form << "\n";
    } catch (const std::runtime_error& exception) {
        std::cout << *this << " couldn't execute " << form;
        std::cout << " because " << exception.what() << "\n";
    }
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
