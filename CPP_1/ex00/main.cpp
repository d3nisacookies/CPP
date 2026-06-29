#include "Zombie.hpp"

int	main(void)
{
	Zombie *z = newZombie("Carl");
	z->announce();
	delete z;

	randomChump("Cassie");
	return (0);
}