#include <cstdlib>
#include <ctime>
#include <iostream>
#include <new>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    switch (rand() % 3) {
        case 0:  return new(std::nothrow) A();
        case 1:  return new(std::nothrow) B();
        default: return new(std::nothrow) C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) std::cout << "A";
    if (dynamic_cast<B*>(p)) std::cout << "B";
    if (dynamic_cast<C*>(p)) std::cout << "C";
}

void identify(Base& p)
{
    try { dynamic_cast<A&>(p); std::cout << "A"; } catch (std::bad_cast&) {}
    try { dynamic_cast<B&>(p); std::cout << "B"; } catch (std::bad_cast&) {}
    try { dynamic_cast<C&>(p); std::cout << "C"; } catch (std::bad_cast&) {}
}

int main()
{
    // Seed the random number generator.
    srand(time(nullptr));

    // Identify some random objects using pointers.
    std::cout << "With pointers:   ";
    for (int i = 0; i < 30; i++) {
        Base* object = generate();
        if (object != nullptr) {
            identify(object);
            delete object;
        }
    }
    std::cout << "\n";

    // Identify some random objects using references.
    std::cout << "With references: ";
    for (int i = 0; i < 30; i++) {
        Base* object = generate();
        if (object != nullptr) {
            identify(*object);
            delete object;
        }
    }
    std::cout << "\n";
}
