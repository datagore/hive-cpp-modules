#pragma once

#include <string>

class RPN
{
public:
    static int calculate(const std::string& expression);

private:
    RPN() = delete;
    ~RPN() = delete;
    RPN(const RPN&) = delete;
    RPN& operator=(const RPN&) = delete;
};
