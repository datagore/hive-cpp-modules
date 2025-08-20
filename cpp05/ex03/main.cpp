#include <filesystem>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Helper macros for ANSI color codes.
#define ANSI_YELLOW "\x1b[1;33m"
#define ANSI_GREEN  "\x1b[1;32m"
#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[0m"

// Run a piece of code via a function pointer, and print out any exception that
// gets thrown.
void run_test(const char *label, void (*test_code)())
{
    static int counter;
    std::cout << ANSI_YELLOW << "\n>>>>> Test #" << ++counter << ": ";
    std::cout << ANSI_RESET << label << "\n";
    try {
        test_code();
    } catch (std::exception& exception) {
        std::cout << ANSI_RED << "Error ";
        std::cout << ANSI_RESET << exception.what() << "\n";
    }
}

int main()
{
    run_test("Create, sign, and execute a shrubbery creation form", [] {
        Intern intern;
        Bureaucrat bureaucrat("Bob", 1);
        AForm* form = intern.makeForm("shrubbery creation", "Garden");
        if (form != nullptr) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
        }
        std::filesystem::remove("Garden_shrubbery");
        delete form;
    });

    run_test("Create, sign, and execute a robotomy request form", [] {
        Intern intern;
        Bureaucrat bureaucrat("Bob", 1);
        AForm* form = intern.makeForm("robotomy request", "Dan");
        if (form != nullptr) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
        }
        delete form;
    });

    run_test("Create, sign, and execute a presidential pardon form", [] {
        Intern intern;
        Bureaucrat bureaucrat("Bob", 1);
        AForm* form = intern.makeForm("presidential pardon", "Richard Nixon");
        if (form != nullptr) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
        }
        delete form;
    });

    run_test("Attempt to create an invalid form", [] {
        Intern intern;
        Bureaucrat bureaucrat("Bob", 1);
        AForm* form = intern.makeForm("fake form", "fake target");
        if (form != nullptr) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
        }
        delete form;
    });
}
