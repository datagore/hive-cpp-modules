#include <iostream>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    AForm* form = nullptr;
    switch (getFormID(name)) {
        case 0: form = new ShrubberyCreationForm(target); break;
        case 1: form = new RobotomyRequestForm(target); break;
        case 2: form = new PresidentialPardonForm(target); break;
        default: break;
    }
    if (form != nullptr)
        std::cout << "Intern creates " << *form << "\n";
    else
        std::cout << "Intern could not create " << name << "\n";
    return form;
}

int Intern::getFormID(const std::string& form)
{
    static const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
    };
    const int formCount = sizeof(formNames) / sizeof(*formNames);
    for (int i = 0; i < formCount; i++)
        if (formNames[i] == form)
            return i;
    return -1;
}
