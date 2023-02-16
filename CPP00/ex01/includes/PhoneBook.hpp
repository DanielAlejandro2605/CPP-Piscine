#ifndef PHONEBOOK
# define PHONEBOOK

# include <iostream>
# include <stdlib.h>
# include "../includes/Contact.hpp"
class PhoneBook
{
    private:
        Contact listContacts[10];
        unsigned int contactSaved;
    public:
        std::string buffer;
        PhoneBook(/* args */);
        ~PhoneBook();
        void appendContactSaved(void);
        Contact *getListContacts(void);
        void Prompt(std::string prompt_message);
        void OpenPhoneBook(void);
        void App(void);
        void AddContact(void);
};

#endif