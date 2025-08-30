#pragma once

#include <vector>

// ANSI escape codes.
#define ANSI_RED    "\x1b[1;31m"
#define ANSI_GREEN  "\x1b[1;32m"
#define ANSI_YELLOW "\x1b[1;33m"
#define ANSI_RESET  "\x1b[0m"

void mergeInsertionSort(const std::vector<int>& numbers);
