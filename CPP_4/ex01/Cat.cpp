#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called." << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &assn)
{
    if (this != &assn)
    {
        this->type = assn.type;
        delete this->brain;
        this->brain = new Brain(*assn.brain);
    }
    std::cout << "Cat copy assignment operator called." << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}