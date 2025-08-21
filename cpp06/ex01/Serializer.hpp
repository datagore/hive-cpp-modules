#pragma once

#include <cstdint>

struct Data;

class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer() = delete;
};
