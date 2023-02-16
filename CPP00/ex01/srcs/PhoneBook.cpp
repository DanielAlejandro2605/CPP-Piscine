#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contactSaved = 0;
}

PhoneBook::~PhoneBook(void)
{

}

void PhoneBook::appendContactSaved(void)
{
	this->contactSaved += 1;
}

Contact *PhoneBook::getListContacts(void)
{
    return this->listContacts;
}

void PhoneBook::Prompt(std::string prompt_message)
{
    this->buffer.clear();
    std::cout << prompt_message << ": ";
	while (this->buffer.empty())
	{
		std::cin >> this->buffer;
		std::cout << "\n";
	}
}

void PhoneBook::OpenPhoneBook(void)
{
	std::cout << "Welcome to PhoneBook App!\n";
	PhoneBook::Prompt("Enter your choice");
}

void PhoneBook::App(void)
{
    if (this->buffer.compare("ADD") == 0)
        this->AddContact();
    else if (this->buffer.compare("SEARCH") == 0)
        std::cout << "Here we search a Contact!\n";
    else if (this->buffer[0] == 0)
        std::cout << "\n";
    this->buffer.clear();
}

void PhoneBook::AddContact(void)
{
	int	free_index = this->contactSaved;
    Contact *arrayContact = this->getListContacts();
    this->Prompt("\tEnter user first name");
    arrayContact[free_index].setFirstName(this->buffer);
    std::cout << arrayContact[free_index].getFirstName();
	std::system("clear");
}