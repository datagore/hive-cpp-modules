#include "Bureaucrat.hpp"

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
    run_test("Construct with a too high grade", [] {
        Bureaucrat bureaucrat("Zero", 0);
        std::cout << ANSI_GREEN << "Constructed " ANSI_RESET << bureaucrat;
    });

    run_test("Construct with a too low grade", [] {
        Bureaucrat bureaucrat("Lowbie", 151);
        std::cout << ANSI_GREEN << "Constructed " ANSI_RESET << bureaucrat;
    });

    run_test("Construct with an acceptably high grade", [] {
        Bureaucrat bureaucrat("Boss man", 1);
        std::cout << ANSI_GREEN << "Constructed " ANSI_RESET << bureaucrat;
    });

    run_test("Construct with an acceptably low grade", [] {
        Bureaucrat bureaucrat("Newbie", 150);
        std::cout << ANSI_GREEN << "Constructed " ANSI_RESET << bureaucrat;
    });

    run_test("Increment grade until too high", [] {
        Bureaucrat bureaucrat("Corporate climber", 3);
        while (true) {
            std::cout << ANSI_GREEN << "Promoted " ANSI_RESET << bureaucrat;
            bureaucrat.incrementGrade();
        }
    });

    run_test("Decrement grade until too low", [] {
        Bureaucrat bureaucrat("Hopeless fuck-up", 148);
        while (true) {
            std::cout << ANSI_GREEN << "Demoted " ANSI_RESET << bureaucrat;
            bureaucrat.decrementGrade();
        }
    });
}
