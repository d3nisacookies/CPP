#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
private:
    int index;
    Contact contact[8];
    std::string PromptField(const std::string &msg);
    std::string truncate(std::string str);

public:
    void add();
    PhoneBook();
    ~PhoneBook();
    void search();
    void print_contact(int index);
};
#endif