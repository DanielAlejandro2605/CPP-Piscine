#ifndef PHONEBOOK
# define PHONEBOOK

# include <iostream>
# include <stdlib.h>
# include "../includes/Contact.hpp"
class PhoneBook
{
    private:
        Contact			listContacts[8];
        std::string		buffer;
        int				contactSaved;
    public:
        PhoneBook(/* args */);
        ~PhoneBook();
        void 			appendContactSaved(void);
		int				getContactSaved(void);
        Contact			*getListContacts(void);
        std::string		getPhoneBookBuffer(void);
        int				Prompt(std::string prompt_message);
        void			OpenPhoneBook(void);
        void			App(std::string cmd);
        void			AddContact(void);
};

#endif