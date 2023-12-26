#ifndef CONTACT
# define CONTACT

# include <iostream>
# include <ctime>
class Contact
{
    private:
        std::string	first_name;
        std::string	last_name;
		std::string	nick_name;
        std::string	phone_number;
		std::string	darkest_secret;
        std::time_t timestamps_creation;
    public:
        Contact(void);
        ~Contact();
		void		setFirstName(std::string first_name_value);
		std::string	getFirstName(void);
		void		printFirstName(void);
        void		setLastName(std::string last_name_value);
        std::string	getLastName(void);
        void		setNickName(std::string nick_name_value);
        std::string	getNickName(void);
        void		setPhoneNumber(std::string phone_number_value);
        std::string getPhoneNumber(void);
        void		setDarkestSecret(std::string darkest_secret_value);
        std::string	getDarkestSecret(void);
        void        setTimeStampsCreation(void);
        std::time_t getTimeStampsCreation(void);
        void		printAllUserInfo(void);
};

#endif
