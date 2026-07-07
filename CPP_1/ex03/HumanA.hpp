#ifndef HUMAN_A
# define HUMAN_A

# include "Weapon.hpp"

class HumanA
{
  private:
	std::string name;
	Weapon &type;

  public:
	HumanA(std::string name, Weapon &Weapon);
	~HumanA();
	void attack();
};

#endif
