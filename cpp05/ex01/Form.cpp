#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
    : Form("Blank form", 150, 150)
{
}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : name(name),
      signGrade(checkGrade(signGrade)),
      execGrade(checkGrade(execGrade)),
      isSigned(false)
{
}

const std::string& Form::getName() const
{
    return name;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecGrade() const
{
    return execGrade;
}

bool Form::getSigned() const
{
    return isSigned;
}

void Form::beSigned(const Bureaucrat& signer)
{
    if (signer.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

int Form::checkGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return grade;
}

Form::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("grade is too high")
{
}

Form::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("grade is too low")
{
}

std::ostream& operator<<(std::ostream& stream, const Form& form)
{
    stream << "form " << form.getName();
    stream << " (" << form.getSignGrade();
    stream << "/" << form.getExecGrade();
    stream << "/" << (form.getSigned() ? "signed)" : "not signed)");
    return stream;
}
