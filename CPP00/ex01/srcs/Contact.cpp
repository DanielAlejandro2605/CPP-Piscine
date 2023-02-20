#include "../includes/Contact.hpp"

Contact::Contact(void)
{
    
}

Contact::~Contact()
{

}

void Contact::setFirstName(std::string first_name_value)
{
    this->first_name.assign(first_name_value);
}

std::string Contact::getFirstName(void)
{
    return (Contact::first_name);
}

void Contact::printFirstName(void)
{
    std::cout << this->first_name << "\n";
}

void Contact::setLastName(std::string last_name_value)
{
    this->last_name.assign(last_name_value);
}

std::string Contact::getLastName(void)
{
    return this->last_name;
}

void Contact::setNickName(std::string nick_name_value)
{
    this->nick_name.assign(nick_name_value);
}

std::string Contact::getNickName(void)
{
    return this->nick_name;
}

void Contact::setPhoneNumber(std::string phone_number_value)
{
    this->phone_number.assign(phone_number_value);
}

std::string Contact::getPhoneNumber(void)
{
    return this->phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret_value)
{
    this->darkest_secret.assign(darkest_secret_value);
}

std::string Contact::getDarkestSecret(void)
{
    return	this->darkest_secret;
}

void Contact::setTimeStampsCreation(void)
{
    this->timestamps_creation = time(0);
}

std::time_t Contact::getTimeStampsCreation(void)
{
    return (this->timestamps_creation);
}

void    Contact::printAllUserInfo(void)
{
    std::cout << Contact::getFirstName() << "\n";
    std::cout << Contact::getLastName() << "\n";
    std::cout << Contact::getNickName() << "\n";
    std::cout << Contact::getPhoneNumber() << "\n";
    std::cout << Contact::getDarkestSecret() << "\n";
}
