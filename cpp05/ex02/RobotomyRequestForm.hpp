#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:
    RobotomyRequestForm() = delete;
    ~RobotomyRequestForm() = default;
    RobotomyRequestForm(const RobotomyRequestForm&) = default;
    RobotomyRequestForm& operator=(const RobotomyRequestForm&) = delete;
    explicit RobotomyRequestForm(const std::string& target);
    void execute(const Bureaucrat& executor) override;

private:
    std::string target;
};
