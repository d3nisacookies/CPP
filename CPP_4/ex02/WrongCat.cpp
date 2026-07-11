#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Wrong Cat constructor called" << std::endl;
    this->type = "Wrong Cat";
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong Cat desctuctor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "Wrong Cat copy constructor called." << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &assn)
{
    if (this != &assn)
    {
        this->type = assn.type;
    }
    std::cout << "Wrong Cat copy assignemnt operator called." << std::endl;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Meow" << std::endl;
}
