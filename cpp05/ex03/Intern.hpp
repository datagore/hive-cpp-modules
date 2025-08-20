#pragma once

#include <string>

class AForm;

class Intern
{
public:
    Intern() = default;
    ~Intern() = default;
    Intern(const Intern&) = default;
    Intern& operator=(const Intern&) = default;

    AForm* makeForm(const std::string& form, const std::string& target) const;

private:
    static int getFormID(const std::string& form);
};
