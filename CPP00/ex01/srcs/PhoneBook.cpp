#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contactSaved = 0;
	this->maxContactCapacity = 8;
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

void	PhoneBook::setPhoneBookBuffer(std::string new_buffer)
{
	this->buffer = new_buffer;
}

std::string PhoneBook::numToString(int value)
{
	std::string			result;
	std::ostringstream	convert;

	convert << value;
	result = convert.str(); 
	return (result);
}

int	PhoneBook::stringToNumber(std::string str)
{
	int result;

	std::istringstream convert(str);
	if (!(convert >> result))
    	result = 0;
	return (result);
}

int	handleString(std::string str, int length_max)
{
	if ((int)str.size() > length_max)
	{
		std::cout << "\tMax " << length_max << " characters!\n";
		return (1);
	}
	return (0);
}

int	handleStringNumber(std::string str, int length_max)
{
	int	i;
	int	size_str;

	size_str = (int)str.size();
	if (size_str > length_max)
	{
		std::cout << "\tMax " << length_max << " characters!\n";
		return (1);
	}
	if (size_str < 10)
	{
		std::cout << "\tMin 10 characters!\n";
		return (1);
	}
	i = 0;
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] == 32) || (str[i] == '+' && i == 0))
		i++;
	if (i == size_str)
		return (0);
	std::cout << "\tOnly digit characters and '+' at the beginning!\n";
	return (1);
}

int	PhoneBook::Prompt(std::string prompt_message, int length, int (*f)(std::string, int))
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
		if (f(buffer, length) || buffer.empty())
		{
			buffer.clear();
		}
		else
			break ;
	}
	PhoneBook::setPhoneBookBuffer(buffer);
	return (0);
}


int		PhoneBook::getFreeIndexArray(Contact *arrayContact, int *addContactSaved)
{
	int	currentAmtContact = PhoneBook::getContactSaved();
	int	index;
	int iterator;

	if (currentAmtContact == PhoneBook::maxContactCapacity)
	{
		iterator = 0;
		index = 0;
		while (iterator < currentAmtContact)
		{
			if (arrayContact[iterator].getTimeStampsCreation() < arrayContact[index].getTimeStampsCreation())
				index = iterator;
			iterator++;
		}
		*addContactSaved = 0;
	}
	else
	{
		index = currentAmtContact;
		*addContactSaved = 1;
	}
	return (index);
}
void    PhoneBook::printFieldContact(std::string info_field)
{
	std::cout << "|";
    if (info_field.length() > 10)
    {
        std::cout << info_field.substr(0, 9) << ".";
    }
    else
    {
        std::cout << std::setw(10);
		std::cout << info_field;
    }
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
            if (PhoneBook::App(buffer))
				break ;
        }
        else
        {
			std::cout << "\n";
            buffer.clear();
			break ;
        }
        buffer.clear();
    }
}

int	PhoneBook::App(std::string cmd)
{
    if (cmd.compare("ADD") == 0)
	{
		if (PhoneBook::AddContact())
		{
			PhoneBook::buffer.clear();
			return (1);
		}
	}
    else if (cmd.compare("SEARCH") == 0)
        PhoneBook::SearchContact();
    PhoneBook::buffer.clear();
	return (0);
}

int	PhoneBook::AddContact(void)
{
	Contact *arrayContact;
	int		addContactSaved;

	arrayContact = PhoneBook::getListContacts();
	int	free_index = PhoneBook::getFreeIndexArray(arrayContact, &addContactSaved);
    if (PhoneBook::Prompt("\tEnter new user first name", 15, &handleString))
		return (1);
    arrayContact[free_index].setFirstName(PhoneBook::buffer);
	if (PhoneBook::Prompt("\tEnter new user last name", 15, &handleString))
		return (1);
    arrayContact[free_index].setLastName(PhoneBook::buffer);
    if (PhoneBook::Prompt("\tEnter new user nick name", 15, &handleString))
		return (1);
    arrayContact[free_index].setNickName(PhoneBook::buffer);
    if (PhoneBook::Prompt("\tEnter new user phone number", 20, &handleStringNumber))
		return (1);
	arrayContact[free_index].setPhoneNumber(PhoneBook::buffer);
	if (PhoneBook::Prompt("\tTell me a darkest secret from this new user", 50, &handleString))
		return (1);
	arrayContact[free_index].setDarkestSecret(PhoneBook::buffer);
	arrayContact[free_index].setTimeStampsCreation();
	if (addContactSaved)
		PhoneBook::appendContactSaved();
	return (0);
}

void	PhoneBook::printContactList(void)
{
	Contact *arrayContact = PhoneBook::getListContacts();
	int	amt_contacts_saved = PhoneBook::getContactSaved();
	int	iterator = 0;

	while (iterator < amt_contacts_saved)
	{
		PhoneBook::printFieldContact(numToString(iterator + 1));
		PhoneBook::printFieldContact(arrayContact[iterator].getFirstName());
		PhoneBook::printFieldContact(arrayContact[iterator].getLastName());
		PhoneBook::printFieldContact(arrayContact[iterator].getNickName());
		std::cout << "|\n";
		iterator++;
	}
}

void	PhoneBook::SearchContact(void)
{
	Contact		*arrayContact;
	std::string buffer;
	int			index_choice;
	int			amt_contacts_saved;

	arrayContact = PhoneBook::getListContacts();
	amt_contacts_saved = PhoneBook::getContactSaved();
	if (amt_contacts_saved > 0)
	{
		buffer = PhoneBook::getPhoneBookBuffer();
		std::cout << "Your contacts!\n";
		PhoneBook::printContactList();
		while (1)
		{
			std::cout << "Enter your index of user : ";
			std::getline(std::cin, buffer);
			if(!std::cin.eof())
			{
				index_choice = PhoneBook::stringToNumber(buffer);
				if (index_choice == 0 || index_choice > amt_contacts_saved)
				{
					std::cout << "Not valid index!\n";
					buffer.clear();
				}
				else
				{
					break ;
				}
			}
			else
			{
				std::cout << "\n";
				return ;
			}
			buffer.clear();
		}
		arrayContact[index_choice - 1].printAllUserInfo();
	}
	else
	{
		std::cout << "You don't have any contact saved ):\n";
	}
}
