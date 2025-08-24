#pragma once

class PmergeMe
{
public:
    PmergeMe() = default;
    ~PmergeMe() = default;
    PmergeMe(const PmergeMe&) = default;
    PmergeMe& operator=(const PmergeMe&) = default;
    PmergeMe(int argc, char **argv);
};
