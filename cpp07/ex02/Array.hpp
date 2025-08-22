#pragma once

#include <stdexcept>

template <typename T>
class Array
{
public:

    explicit Array(unsigned int n=0)
        : data(new T[n]()),
          n(n)
    {
    }

    Array(const Array& other)
        : data(new T[other.n]),
          n(other.n)
    {
        for (size_t i = 0; i < n; i++)
            data[i] = other.data[i];
    }

    Array& operator=(const Array& other)
    {
        if (this != &other) {
            delete[] data;
            data = new T[other.n];
            for (size_t i = 0; i < n; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    ~Array()
    {
        delete[] data;
        data = nullptr;
        n = 0;
    }

    T& operator[](unsigned int index)
    {
        if (index >= n)
            throw std::out_of_range("index out of range");
        return data[index];
    }

    const T& operator[](unsigned int index) const
    {
        if (index >= n)
            throw std::out_of_range("index out of range");
        return data[index];
    }

    unsigned int size() const
    {
        return n;
    }

private:

    T* data;
    unsigned int n;
};
