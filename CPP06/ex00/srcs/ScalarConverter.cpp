#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter(std::string arg) : _arg(arg)
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		this->_arg = rhs.getArg();
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScalarConverter::convert() {
	if (this->_arg.empty())
	{
		std::cout << "It's empty" << std::endl;
		throw ScalarConverter::InvalidInput();
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string ScalarConverter::getArg(void) const
{
	return (this->_arg);
}

/* ************************************************************************** */