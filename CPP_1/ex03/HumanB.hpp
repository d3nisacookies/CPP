#ifndef HUMAN_B
# define HUMAN_B

# include "Weapon.hpp"

class HumanB
{
  private:
	std::string name;
	Weapon *type;

  public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &Weapon);
	void attack();
};

#endif