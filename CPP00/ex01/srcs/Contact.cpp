#include "../includes/Contact.hpp"

Contact::Contact(void)
{
    
}

Contact::~Contact()
{

}

void Contact::setFirstName(std::string first_name_value)
{
    this->first_name = first_name_value;
}

std::string Contact::getFirstName(void)
{
    return this->first_name;
}

void Contact::printFirstName(void)
{
    std::cout << this->first_name << "\n";
}

void Contact::setLastName(std::string last_name_value)
{
    this->last_name = last_name_value;
}

std::string Contact::getLastName(void)
{
    return this->last_name;
}

void Contact::setNickName(std::string nick_name_value)
{
    this->nick_name = nick_name_value;
}

std::string Contact::getNickName(void)
{
    return this->nick_name;
}

void Contact::setPhoneNumber(std::string phone_number_value)
{
    this->phone_number = phone_number_value;
}

std::string Contact::getPhoneNumber(void)
{
    return this->phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret_value)
{
    this->darkest_secret = darkest_secret_value;
}

std::string Contact::getDarkestSecretr(void)
{
    return	this->darkest_secret;
}


