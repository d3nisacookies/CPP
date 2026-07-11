#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iomanip>
#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &assn);
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif