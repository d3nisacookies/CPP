#pragma once

#include "Data.hpp"
#include <string>

#include <iostream>
#include <stdint.h>

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& cpy);
        Serializer& operator=(const Serializer& assn);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};