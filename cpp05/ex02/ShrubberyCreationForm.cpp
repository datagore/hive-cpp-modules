#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137),
      target(target)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
    checkRequirements(executor);
    std::ofstream file(target + "_shrubbery", std::ios::out | std::ios::trunc);
    if (file.is_open())
        file << "🌳🌳🌳🌲🌲🌲🌴🌴🌴";
}
