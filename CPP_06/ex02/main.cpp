#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

Base* generate()
{
    int random;

    random = std::rand() % 3;
    if (random == 0)
        return new A();
    if (random == 1)
        return new B();
    return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}
void identify(Base &p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }catch(...)
    {
    }
        try
    {
        dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }catch(...)
    {
    }
        try
    {
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }catch(...)
    {
    }
}



int main(void)
{
    std::srand(std::time(NULL));
    Base *base = generate();

    identify(base);
    identify(*base);
    delete base;
    return 0;
}
