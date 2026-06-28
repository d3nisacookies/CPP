#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::SetFields(std::string FirstName, std::string LastName, std::string Number, std::string Nickname, std::string DarkestSecret)
{
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->Number = Number;
    this->Nickname = Nickname;
    this->DarkestSecret = DarkestSecret;
}

std::string Contact::GetFirstName()
{
    return (FirstName);
}

std::string Contact::GetLastName()
{
    return (LastName);
}

std::string Contact::GetNumber()
{
    return (Number);
}

std::string Contact::GetNickname()
{
    return (Nickname);
}

std::string Contact::GetDarkestSecret()
{
    return (DarkestSecret);
}