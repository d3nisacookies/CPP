#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), type(NULL)
{
	std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << name << " destructed" << std::endl;
}

void HumanB::attack(void)
{
	if (!type)
	{
		std::cout << name << " does not have a weapon" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
	this->type = &Weapon;
}