#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
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
	(void)rhs;
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

void	ScalarConverter::convert(const std::string	&arg){
	long long 	num_long;
	double		num_double;
	char		*delim_long_ptr;
	char		*delim_double_ptr;

	if (arg.empty())
	{
		throw ScalarConverter::InvalidInput();
	}
	else if (arg.size() == 1)
	{
		if (isdigit(arg.at(0)))
		{
			this->_int_value = static_cast<int>(strtol(arg.c_str(), NULL, 10));
			this->_type = INTEGER;
		}
		else
		{
			this->_char_value = isdigit(arg.at(0));
			this->_type = CHARACTER;
		}
	}
	else
	{
		num_long= strtoll(arg.c_str(), delim_long_ptr, 10);
		num_double = str
		if ((num == LLONG_MAX || num == LLONG_MIN) && errno == ERANGE) {
			std::cout << "El número está fuera del rango válido para long long int." << std::endl;
		} else {
			std::cout << "Número convertido: " << num << std::endl;
		}
	}
}

// bool	ScalarConverter::IsPseudoLiteral(const std::string &arg) {
// 	std::string	pseudo_literal[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
// 	for (int i = 0; i < 6; i++)
// 	{
// 		std::cout << (arg.find(pseudo_literal[i], 0)) << std::endl;
// 	}
// 	return (true);
// }

// bool	ScalarConverter::IsChar(const std::string	&arg)
// {
// 	if (arg.size() == 1)
// 	{
// 		std::cout << "oui" << std::endl;
// 		std::cout << (arg[0] > 25) << std::endl;
// 	}
// 	std::cout << arg.size() << std::endl;
// 	return (true);
// }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
// std::string ScalarConverter::getArg(void) const
// {
// 	return (this->_arg);
// }

/* ************************************************************************** */