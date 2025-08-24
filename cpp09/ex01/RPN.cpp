#include <cctype>
#include <climits>
#include <stack>
#include <stdexcept>

#include "RPN.hpp"

int RPN::calculate(const std::string& expression)
{
    // Use a stack to store intermediate values.
    std::stack<int> stack;

    // Iterate over characters in the expression.
    for (char c: expression) {

        // Digits are pushed directly to the stack.
        if (std::isdigit(c)) {
            stack.push(c - '0');

        // Any other non-space character is an operator.
        } else if (!std::isspace(c)) {

            // Get the top two values from the stack.
            if (stack.size() < 2)
                throw std::invalid_argument("unbalanced expression");
            long rhs = stack.top(); stack.pop(); // Right-hand side.
            long lhs = stack.top(); stack.pop(); // Left-hand side.

            // Do arithmetic.
            long res;
            switch (c) {
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
