#include <iostream>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (...)
    {
        std::cout << "not A" << std::endl;
    }
}

int main()
{
    B b;
    identify(b);
}