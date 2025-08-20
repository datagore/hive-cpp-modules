#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : name(name),
      signGrade(checkGrade(signGrade)),
      execGrade(checkGrade(execGrade)),
      isSigned(false)
{
}

const std::string& AForm::getName() const
{
    return name;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecGrade() const
{
    return execGrade;
}

bool AForm::getSigned() const
{
    return isSigned;
}

void AForm::beSigned(const Bureaucrat& signer)
{
    if (signer.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

int AForm::checkGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return grade;
}

void AForm::checkRequirements(const Bureaucrat& executor) const
{
    if (!isSigned)
        throw std::runtime_error("form is not signed");
    if (executor.getGrade() > execGrade)
        throw GradeTooLowException();
}

AForm::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("grade is too high")
{
}

AForm::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("grade is too low")
{
}

std::ostream& operator<<(std::ostream& stream, const AForm& form)
{
    stream << "form " << form.getName();
    stream << " (" << form.getSignGrade();
    stream << "/" << form.getExecGrade();
    stream << "/" << (form.getSigned() ? "signed)" : "not signed)");
    return stream;
}
