#ifndef PHONEBOOK
# define PHONEBOOK

# include <iomanip>
# include <sstream>
# include "../includes/Contact.hpp"
class PhoneBook
{
    private:
        Contact			listContacts[8];
        std::string		buffer;
        int				contactSaved;
        int             maxContactCapacity;           
    public:
        PhoneBook(/* args */);
        ~PhoneBook();
        void 			appendContactSaved(void);
		int				getContactSaved(void);
        Contact			*getListContacts(void);
        std::string		getPhoneBookBuffer(void);
        void            setPhoneBookBuffer(std::string new_buffer);
        int             Prompt(std::string prompt_message, int length, int (*f)(std::string, int));
        int		        getFreeIndexArray(Contact *arrayContact, int *addContactSaved);
        void            printFieldContact(std::string info_field);
        void			OpenPhoneBook(void);
        int             App(std::string cmd);
        int             AddContact(void);
        void            printContactList(void);
        void            SearchContact(void);
};

#endif