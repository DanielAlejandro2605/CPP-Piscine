#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", target, 72, 45)
{
	std::cout << YELLOW << "RobotomyRequestForm constructor called!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	std::cout << YELLOW << "RobotomyRequestForm copy constructor called!" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "RobotomyRequestForm destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	this->AForm::operator=(rhs);
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
	
void	RobotomyRequestForm::action(Bureaucrat const &executor) const {
	this->AForm::execute(executor);
	std::cout << BGYELLOW << "Making some drilling noises" << RESET << std::endl;
	std::srand(std::time(0));
	if ((rand() % 100) < 50)
		std::cout << RED << this->getTarget() << " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed!" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */