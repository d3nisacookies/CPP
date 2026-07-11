#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong Animal Deconstructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "Wrong Animal Copy constructor called." << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assn)
{
    if (this != &assn)
    {
        this->type = assn.type;
    }
    std::cout << "Wrong Animal copy assignment operator called." << std::endl;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong Animal sounds." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}