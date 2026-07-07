#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : name(name), type(Weapon)
{
	std::cout << "HumanA " << name << " constructed" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << " destructed" << std::endl;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << type.getType() << std::endl;
}