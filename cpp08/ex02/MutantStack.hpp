#pragma once

#include <stack>

template <typename T, typename Container=typename std::stack<T>::container_type>
class MutantStack: public std::stack<T, Container>
{
public:

    // Orthodox Canonical stuff (all defaulted).
    MutantStack() = default;
    ~MutantStack() = default;
    MutantStack(const MutantStack&) = default;
    MutantStack& operator=(const MutantStack&) = default;

    // Aliases for iterator types.
    using iterator               = typename Container::iterator;
    using const_iterator         = typename Container::const_iterator;
    using reverse_iterator       = typename Container::reverse_iterator;
    using const_reverse_iterator = typename Container::const_reverse_iterator;

    // Mutable forward iteration.
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end();   }

    // Mutable reverse iteration.
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend()   { return this->c.rend();   }

    // Constant forward iteration.
    const_iterator begin()  const { return this->c.begin();  }
    const_iterator cbegin() const { return this->c.cbegin(); }
    const_iterator end()    const { return this->c.end();    }
    const_iterator cend()   const { return this->c.cend();   }

    // Constant reverse iteration.
    const_reverse_iterator rbegin()  const { return this->c.rbegin();  }
    const_reverse_iterator crbegin() const { return this->c.crbegin(); }
    const_reverse_iterator rend()    const { return this->c.rend();    }
    const_reverse_iterator crend()   const { return this->c.crend();   }
};
