#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", target, 25, 5)
{
	std::cout << CYAN << "PresidentialPardonForm constructor called!" << RESET << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	std::cout << CYAN << "PresidentialPardonForm copy constructor called!" << RESET << std::endl; 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN << "PresidentialPardonForm destructor called!" << RESET << std::endl; 
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	this->AForm::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::action(Bureaucrat const &executor) const {
	this->AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */