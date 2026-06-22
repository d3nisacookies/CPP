#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string number;
	std::string nickname;
	std::string darkestSecret;

  public:
	std::string getFirstName();
	std::string getLastName();
	std::string getNumber();
	std::string getNickname();
	std::string getDarkestSecret();
	void setFields(std::string firstName, std::string lastName,
		std::string number, std::string nickname, std::string darkestSecret);
};

class PhoneBook
{
  private:
	int index;
	Contact contact[8];
	std::string promptField(const std::string &msg);
	std::string truncate(std::string str);

  public:
	void add();
	void search();
	void print_contact(int index);
};

#endif
