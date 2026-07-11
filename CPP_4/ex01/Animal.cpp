#include "Animal.hpp"

Animal::Animal()
{
    std::cout << this->type << "Animal Constructor called." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called." << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal Copy constructor called." << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &assn)
{
    std::cout << "Animal copy Assignment operator called" << std::endl;
    if (this != &assn)
    {
        this->type = assn.type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}