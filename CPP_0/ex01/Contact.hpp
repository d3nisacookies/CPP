#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string Number;
    std::string Nickname;
    std::string DarkestSecret;

public:
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNumber();
    std::string GetNickname();
    std::string GetDarkestSecret();
    void SetFields(std::string FirstName, std::string LastName, std::string Number, std::string Nickname, std::string DarkestSecret);
    Contact();
    ~Contact();
};

#endif