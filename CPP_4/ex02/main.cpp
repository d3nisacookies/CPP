#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *k = new Cat();
    Animal *animals[10];
    Dog a;

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            animals[i] = new Dog();
        }
        else
        {
            animals[i] = new Cat();
        }
    }

    a.getBrain()->setIdea(0, "i like humping.");
    Dog b(a);

    a.getBrain()->setIdea(0, "i hate cats");

    std::cout << a.getBrain()->getIdea(0) << std::endl;
    std::cout << b.getBrain()->getIdea(0) << std::endl;

    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }
    delete j;
    delete k;
    return 0;
}
