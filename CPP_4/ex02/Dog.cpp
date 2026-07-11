#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->brain = NULL;
    *this = copy;
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &assn)
{
    if (this != &assn)
    {
        this->type = assn.type;
        delete this->brain;
        this->brain = new Brain(*assn.brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain() const
{
    return (this->brain);
}