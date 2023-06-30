#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice()
	: AMateria("Ice")
{
	std::cout << BGBLUE << "Ice constructor called!" << RESET << std::endl;
}

Ice::Ice(const Ice &src)
	: AMateria(src)
{
	std::cout << BGBLUE << "Ice copy constructor called!" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=(Ice const &rhs)
{
	this->AMateria::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void 		Ice::use(ICharacter &target) {
	std::cout << BGBLUE << "* shoots an ice bolt at " << target.getName() << "*" << RESET << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */