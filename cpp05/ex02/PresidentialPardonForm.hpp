#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
    PresidentialPardonForm() = delete;
    ~PresidentialPardonForm() = default;
    PresidentialPardonForm(const PresidentialPardonForm&) = default;
    PresidentialPardonForm& operator=(const PresidentialPardonForm&) = delete;
    explicit PresidentialPardonForm(const std::string& target);
    void execute(const Bureaucrat& executor) const override;

private:
    std::string target;
};
