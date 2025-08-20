#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5),
      target(target)
{
}

void PresidentialPardonForm::execute(const Bureaucrat& executor)
{
    checkRequirements(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
