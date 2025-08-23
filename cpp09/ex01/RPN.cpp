#include <cctype>
#include <climits>
#include <stack>
#include <stdexcept>

#include "RPN.hpp"

int RPN::calculate(const std::string& expression)
{
    char prev = ' ';
    std::stack<int> stack;

    // Iterate over characters in the expression.
    for (char curr: expression) {

        // Require spaces between digits and operators.
        if (!std::isspace(curr) && !std::isspace(prev))
            throw std::invalid_argument("missing space");
        prev = curr;

        // Digits are pushed directly to the stack.
        if (std::isdigit(curr)) {
            stack.push(curr - '0');

        // Any other non-space character is an operator.
        } else if (!std::isspace(curr)) {

            // Get the top two values from the stack.
            if (stack.size() < 2)
                throw std::invalid_argument("unbalanced expression");
            long rhs = stack.top(); stack.pop(); // Right-hand side.
            long lhs = stack.top(); stack.pop(); // Left-hand side.

            // Do arithmetic.
            long res;
            switch (curr) {
                case '+': res = lhs + rhs; break;
                case '-': res = lhs - rhs; break;
                case '*': res = lhs * rhs; break;
                case '/': res = lhs / rhs; break;
                default: throw std::invalid_argument("invalid operator");
            }

            // Check for overflow and push the result to the stack.
            if (res < INT_MIN) throw std::underflow_error("integer underflow");
            if (res > INT_MAX) throw std::overflow_error("integer overflow");
            stack.push(res);
        }
    }

    // Check that there's precisely one value left on the stack at the end.
    if (stack.size() != 1)
        throw std::invalid_argument("unbalanced expression");

    // Return the final result.
    return stack.top();
}
