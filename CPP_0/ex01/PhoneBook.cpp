#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {} // constructor
PhoneBook::~PhoneBook() {}           // destructor

std::string PhoneBook::PromptField(const std::string &msg)
{
    std::string value;
    while (value.empty())
    {
        std::cout << msg << ": ";
        if (!std::getline(std::cin, value))
            return ("");
    }
    return value;
}

void PhoneBook::add()
{
    std::string FirstName = PromptField("First Name");
    std::string LastName = PromptField("last Name");
    std::string Number = PromptField("Number");
    std::string Nickname = PromptField("Nickname");
    std::string DarkestSecret = PromptField("Darkest Secret");
    contact[index].SetFields(FirstName, LastName, Number, Nickname, DarkestSecret);
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
    std::cout << "First Name : " << contact[index].GetFirstName() << std::endl;
    std::cout << "Last Name : " << contact[index].GetLastName() << std::endl;
    std::cout << "Number : " << contact[index].GetNumber() << std::endl;
    std::cout << "Nickname : " << contact[index].GetNickname() << std::endl;
    std::cout << "Darkest Secret : " << contact[index].GetDarkestSecret() << std::endl;
}

void PhoneBook::search()
{
    int i = 0;
    int index;
    while (i < 8)
    {
        if (contact[i].GetFirstName().empty())
        {
            i++;
            continue;
        }
        std::cout << std::setw(10) << i << "|" << std::setw(10) << truncate(contact[i].GetFirstName()) << "|" << std::setw(10) << truncate(contact[i].GetLastName()) << "|" << std::setw(10) << truncate(contact[i].GetNickname()) << "|" << std::endl;
        i++;
    }
    std::cout << "Enter the index you want to view : ";
    std::cin >> index;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    if (index < 0 || index > 7 || contact[index].GetFirstName().empty())
        std::cout << "Invalid Index" << std::endl;
    else
        print_contact(index);
}