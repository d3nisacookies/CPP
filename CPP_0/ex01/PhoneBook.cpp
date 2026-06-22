#include "Phonebook.hpp"

std::string PhoneBook::promptField(const std::string &msg)
{
	std::string value;
	while (value.empty())
	{
		std::cout << msg << ": ";
		std::getline(std::cin, value);
	}
	return (value);
}

void PhoneBook::add()
{
	std::string firstName = promptField("First Name");
	std::string lastName = promptField("Last Name");
	std::string number = promptField("number");
	std::string nickname = promptField("nickname");
	std::string darkestSecret = promptField("darkest Secret");
	contact[index].setFields(firstName, lastName, number, nickname,
		darkestSecret);
	index++;
	if (index >= 8)
		index = 0;
}

std::string PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
	{
		return (str.substr(0, 9) + '.');
	}
	return (str);
}

void PhoneBook::print_contact(int index)
{
	std::cout << "First name: " << contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contact[index].getNickname() << std::endl;
	std::cout << "Number: " << contact[index].getNumber() << std::endl;
	std::cout << "Darkest secret: " << contact[index].getDarkestSecret() << std::endl;
}

void PhoneBook::search()
{
	int i = 0;
	int index;
	while (i < 8)
	{
		if (contact[i].getFirstName().empty())
		{
			i++;
			continue ;
		}
		std::cout << std::setw(10) << i << "|" << std::setw(10) << truncate(contact[i].getFirstName()) << "|" << std::setw(10) << truncate(contact[i].getLastName()) << "|" << std::setw(10) << truncate(contact[i].getNickname()) << "|" << std::endl;
		i++;
	}
	std::cout << "Enter the index of what you want : ";
	std::cin >> index;
	std::cin.ignore();
	if (index < 0 || index > 7 || contact[index].getFirstName().empty())
		std::cout << "Invalid index." << std::endl;
	else
		print_contact(index);
}