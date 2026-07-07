#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	int N = std::atoi(av[1]);
	Zombie *z = zombieHorde(N, "Carl");
	for (int i = 0; i < N; i++)
	{
		z[i].announce();
	}
	delete[] z;
	return (0);
}