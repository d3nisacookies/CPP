#ifndef WEAPON_H
# define WEAPON_H

# include <cstddef>
# include <iostream>
# include <string>

class Weapon
{
  private:
	std::string type;

  public:
	const std::string &getType() const;
	void setType(std::string value);
	Weapon(std::string name);
	~Weapon();
};

#endif
