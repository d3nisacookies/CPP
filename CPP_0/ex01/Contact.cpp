#include "Phonebook.hpp"

void Contact::setFields(std::string firstName, std::string lastName,
	std::string number, std::string nickname, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->number = number;
	this->nickname = nickname;
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
	return (firstName);
}

std::string Contact::getLastName()
{
	return (lastName);
}

std::string Contact::getNumber()
{
	return (number);
}

std::string Contact::getNickname()
{
	return (nickname);
}

std::string Contact::getDarkestSecret()
{
	return (darkestSecret);
}