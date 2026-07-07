#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void (Harl::*funcs[])(void) = {&Harl::debug, &Harl::error, &Harl::info,
		&Harl::warning};
	std::string levels[] = {"DEBUG", "ERROR", "INFO", "WARNING"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "Unknown command for Harl." << std::endl;
}

void Harl::debug(void)
{
	std::cout << "Harl is  debugging." << std::endl;
}

void Harl::error(void)
{
	std::cout << "Harl said it has an error." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Harl is warning you." << std::endl;
}

void Harl::info(void)
{
	std::cout << "Harl is informing you." << std::endl;
}