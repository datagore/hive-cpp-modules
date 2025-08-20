#include <filesystem>
#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"
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
    run_test("Creating a shrubbery with a high enough grade", [] {
        Bureaucrat bureaucrat("Bob", 100);
        ShrubberyCreationForm form("Garden");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
        std::ifstream file("Garden_shrubbery", std::ios::in);
        if (file.is_open())
            std::cout << "Shrubbery contents: " << file.rdbuf() << "\n";
        std::filesystem::remove("Garden_shrubbery");
    });

    run_test("Creating a shrubbery with only a high enough grade to sign", [] {
        Bureaucrat bureaucrat("Bob", 140);
        ShrubberyCreationForm form("Garden");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
        std::ifstream file("Garden_shrubbery", std::ios::in);
        if (file.is_open())
            std::cout << "Shrubbery contents: " << file.rdbuf() << "\n";
        std::filesystem::remove("Garden_shrubbery");
    });

    run_test("Creating a shrubbery with a grade too low to even sign", [] {
        Bureaucrat bureaucrat("Bob", 150);
        ShrubberyCreationForm form("Garden");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
        std::ifstream file("Garden_shrubbery", std::ios::in);
        if (file.is_open())
            std::cout << "Shrubbery contents: " << file.rdbuf() << "\n";
        std::filesystem::remove("Garden_shrubbery");
    });

    run_test("Carrying out ten random robotomies", [] {
        Bureaucrat bureaucrat("Bob", 1);
        RobotomyRequestForm form("Dan");
        bureaucrat.signForm(form);
        for (int i = 0; i < 10; i++)
            bureaucrat.executeForm(form);
    });

    run_test("Attempting robotomies without permission", [] {
        Bureaucrat bureaucrat("Bob", 150);
        RobotomyRequestForm form("Dan");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    });

    run_test("Giving a presidential pardon", [] {
        Bureaucrat bureaucrat("Boss man", 1);
        PresidentialPardonForm form("Richard Nixon");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    });

    run_test("Attempting an unauthorized presidential pardon", [] {
        Bureaucrat bureaucrat("Impostor", 30);
        PresidentialPardonForm form("Richard Nixon");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    });
}
