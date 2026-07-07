#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->type = name;
	std::cout << name << " constructed " << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << type << " deconstructed" << std::endl;
}

const std::string &Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string value)
{
	this->type = value;
}