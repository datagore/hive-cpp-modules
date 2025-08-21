#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    // Make an array of Data objects and store some integers in it, along with
    // boolean values indicating if each value is even or odd.
    enum {COUNT = 10};
    Data numbers[COUNT];
    for (int i = 0; i < COUNT; i++) {
        numbers[i].value = i;
        numbers[i].even = i % 2 == 0;
    }

    // Use the Serialize class to make an array of serialized pointers to Data
    // objects.
    uintptr_t serialized[10];
    for (int i = 0; i < COUNT; i++)
        serialized[i] = Serializer::serialize(&numbers[i]);

    // Deserialize each of the Data objects, printing out their addresses and
    // values.
    for (int i = 0; i < COUNT; i++) {
        Data* data = Serializer::deserialize(serialized[i]);
        std::cout << data << ", " << &numbers[i] << ", ";
        std::cout << data->value << (data->even ? " (even)\n" : " (odd)\n");
    }
}
