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

Contact 	*PhoneBook::getListContacts(void)
{
    return (this->listContacts);
}

int	PhoneBook::getContactSaved(void)
{
    return (this->contactSaved);
}

std::string	PhoneBook::getPhoneBookBuffer(void)
{
    return (this->buffer);
}

int	PhoneBook::Prompt(std::string prompt_message)
{
    std::string buffer = PhoneBook::getPhoneBookBuffer();

	buffer.clear();
	while (buffer.empty())
	{
		std::cout << prompt_message << ": ";
		std::getline(std::cin, buffer);
		if(std::cin.eof())
		{
            buffer.clear();
			return (1);
        }
	}
	return (0);
}

void	PhoneBook::OpenPhoneBook(void)
{
    std::string buffer = PhoneBook::getPhoneBookBuffer();

	std::cout << "Welcome to PhoneBook App!\n";
    std::cout << "You can ADD and SEARCH your contacts!\n";
    while (1)
    {
        std::cout << "Enter your choice : ";
        std::getline(std::cin, buffer);
        if(!std::cin.eof())
        {
            if (buffer.compare("EXIT") == 0)
			{
				buffer.clear();
				break ;
			}
            PhoneBook::App(buffer);
        }
        else
        {
            buffer.clear();
			break ;
        }
        buffer.clear();
    }
}

void PhoneBook::App(std::string cmd)
{
    if (cmd.compare("ADD") == 0)
	{
		PhoneBook::AddContact();
	}
    else if (cmd.compare("SEARCH") == 0)
        std::cout << "Here we search a Contact!\n";
    this->buffer.clear();
}

void PhoneBook::AddContact(void)
{
	Contact *arrayContact = PhoneBook::getListContacts();
	int	free_index = PhoneBook::contactSaved;
	int ctrl_prompt = 0;

    ctrl_prompt = PhoneBook::Prompt("\tEnter new user first name");
	if (ctrl_prompt)
		return ()
    arrayContact[free_index].setFirstName(PhoneBook::buffer);
    PhoneBook::Prompt("\tEnter new user last name");
    arrayContact[free_index].setLastName(PhoneBook::buffer);
    PhoneBook::Prompt("\tEnter new user nick name");
    arrayContact[free_index].setNickName(PhoneBook::buffer);
    PhoneBook::Prompt("\tEnter new user phone number");
	arrayContact[free_index].setPhoneNumber(PhoneBook::buffer);
	PhoneBook::Prompt("\tTell me a darkest secret from this new user");
	arrayContact[free_index].setDarkestSecret(PhoneBook::buffer);
	arrayContact[free_index].printUserInfo();
	std::cout << "Here" << "\n";
}