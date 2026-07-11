#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called." << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain destructor calles" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &assn)
{
    if (this != &assn)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = assn.ideas[i];
        }
    }
    return (*this);
}

std::string Brain::getIdea(int index) const
{
    return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
    this->ideas[index] = idea;
}