#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>


int main(void)
{
    Data d;
    d.id = 1;
    d.value = "42";

    std::cout << d.id << " " << d.value << "." << std::endl;
    uintptr_t a =Serializer::serialize(&d);
    Data* b = Serializer::deserialize(a);
    std::cout << "After serializing: " << a << std::endl;
    std::cout << "After deserializing " << b->id << " " << b->value << std::endl;
    std::cout << (&d == b) << std::endl;
    return (0);
}