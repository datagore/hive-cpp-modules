#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
    ShrubberyCreationForm() = delete;
    ~ShrubberyCreationForm() = default;
    ShrubberyCreationForm(const ShrubberyCreationForm&) = default;
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm&) = delete;
    explicit ShrubberyCreationForm(const std::string& target);
    void execute(const Bureaucrat& executor) override;

private:
    std::string target;
};
