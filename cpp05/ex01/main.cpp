#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    run_test("Create a form with a grade that's too high", [] {
        Form form("Form", 0, 0);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << form << "\n";
    });

    run_test("Create a form with a grade that's too low", [] {
        Form form("Form", 151, 151);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << form << "\n";
    });

    run_test("Create a form with a middling grade", [] {
        Form form("Form", 75, 75);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << form << "\n";
    });

    run_test("Sign a form with a much lower grade", [] {
        Bureaucrat bureaucrat("Boss man", 1);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << bureaucrat << "\n";
        Form form("Basic", 150, 150);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << form << "\n";
        bureaucrat.signForm(form);
    });

    run_test("Sign a form with a much higher grade", [] {
        Bureaucrat bureaucrat("Lowbie", 150);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << bureaucrat << "\n";
        Form form("Secret", 1, 1);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << form << "\n";
        bureaucrat.signForm(form);
    });

    run_test("Sign a form with a matching grade", [] {
        Bureaucrat bureaucrat("Normie", 75);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << bureaucrat << "\n";
        Form form("Everyday", 75, 75);
        std::cout << ANSI_GREEN << "Created " ANSI_RESET << form << "\n";
        bureaucrat.signForm(form);
    });
}
