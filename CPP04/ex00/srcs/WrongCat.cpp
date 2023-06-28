#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << BGBLUE << "WrongCat constructor called!" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << BGBLUE << "WrongCat copy constructor called!" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << BGBLUE << "WrongCat destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// WrongCat &				WrongCat::operator=( WrongCat const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

std::ostream& operator<<(std::ostream &output, WrongCat const &instance_wrong_cat)
{
	output << CYAN << "******************************" RESET <<  std::endl;
	output << CYAN << "********   ANIMAL    *********" RESET <<  std::endl;
    output << BLUE << "| TYPE : " << instance_wrong_cat.getType() << RESET << std::endl;
	output << CYAN << "******************************" RESET <<  std::endl;
	return (output);
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	WrongCat::makeSound(void) const {
	std::cout << BGGREEN << "WrongCat : meow!!!" << RESET << std::endl;	
} 
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */