#pragma once

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T& haystack, int needle)
{
    return std::find(std::begin(haystack), std::end(haystack), needle);
}

template <typename T>
typename T::iterator easyfind(T& haystack, int needle)
{
    return std::find(std::begin(haystack), std::end(haystack), needle);
}
