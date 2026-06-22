#include "Phonebook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;

		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid Command." << std::endl;
	}
	return (0);
}