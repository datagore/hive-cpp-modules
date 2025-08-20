#include <iostream>
#include <random>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45),
      target(target)
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    checkRequirements(executor);
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_real_distribution<> distribution;
    std::cout << "*drilling noises* the robotomy ";
    if (distribution(generator) < 0.5f)
        std::cout << "succeeded!\n";
    else
        std::cout << "failed!\n";
}
