#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iomanip>
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &assn);
    void makeSound() const;
    std::string getType() const;
};

#endif