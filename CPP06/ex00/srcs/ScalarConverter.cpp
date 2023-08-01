#include "ScalarConverter.hpp"

int 	ScalarConverter::_type = NUL;
char 	ScalarConverter::_char_value = 0;
int 	ScalarConverter::_int_value = 0;
float	ScalarConverter::_float_value = 0.0f;
double	ScalarConverter::_double_value = 0.0;

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

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScalarConverter::convert(const std::string	&arg){
	ScalarConverter::setType(arg);
	try {
		std::cout << "char: '" << ScalarConverter::toChar() << "'" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "int: " << ScalarConverter::toInt() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		float f = ScalarConverter::toFloat();
		double p, fraction;
    	fraction = modf(f, &p);
		if (fraction == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		double d = ScalarConverter::toDouble();
		double p, fraction;
    	fraction = modf(d, &p);
		if (fraction == 0)
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}


void	ScalarConverter::setType(const std::string	&arg) {
	long int	num_long;
	double		num_double;
	char		*endptr_long;
	char		*endptr_double;

	if (arg.empty())
		throw ScalarConverter::InvalidInput();
	else if (arg.size() == 1)
	{
		if (isdigit(arg.at(0)))
		{
			ScalarConverter::_int_value = static_cast<int>(std::strtol(arg.c_str(), NULL, 10));
			ScalarConverter::_type = INTEGER;
		}
		else
		{
			ScalarConverter::_char_value = arg.at(0);
			ScalarConverter::_type = CHARACTER;
		}
	}
	else
	{
		if (!isInvalidLiteral(arg))
			throw ScalarConverter::InvalidInput();
		else
		{
			num_long = std::strtol(arg.c_str(), &endptr_long, 10);
			num_double = std::strtod(arg.c_str(), &endptr_double);

			if (*endptr_long == '\0')
			{
				if (num_long > std::numeric_limits<int>::max() || num_long < std::numeric_limits<int>::min())
				{
					throw ScalarConverter::InvalidInput();
				}
				else
				{
					ScalarConverter::_int_value = static_cast<int>(num_long);
					ScalarConverter::_type = INTEGER;
				}
			}
			else
			{
				if (*endptr_double == 'f' && *(endptr_double + 1) == '\0')
				{
					// std::cout << num_double << std::endl;
					ScalarConverter::_float_value = static_cast<float>(num_double);
					// std::cout << ScalarConverter::_float_value << std::endl;
					ScalarConverter::_type = FLOAT;
				}
				else if (*endptr_double == '\0')
				{
					ScalarConverter::_double_value = num_double;
					ScalarConverter::_type = DOUBLE;
				}
			}
		}
	}
}

bool	ScalarConverter::isInvalidLiteral(const std::string	&arg) {
	std::string cases[6] = {"nan", "nanf", "-inff", "+inff", "-inf", "+inf"};
	std::string	sets[4] = {"0123456789", "0123456789-", "0123456789.-f", "0123456789.-"};
	int			i;
	
	for (i = 0; i < 4; i++)
	{
		if ((arg.find_first_not_of(sets[i]) == std::string::npos))
			break;
	}
	if (i == 4)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arg.compare(cases[j]) == 0)
			{
				return (true);
			}
		}
	}
	else
		return (true);
	return (false);
}

char	ScalarConverter::toChar(void)
{
	char c;

	switch(ScalarConverter::_type)
	{
		case CHARACTER:
			c = ScalarConverter::_char_value;
			break;
		case INTEGER:
			c = static_cast<char>(ScalarConverter::_int_value);
			if (ScalarConverter::_int_value > std::numeric_limits<char>::max()
				|| ScalarConverter::_int_value < std::numeric_limits<char>::min())
				throw ScalarConverter::Impossible();
			else if (!isprint(c))
				throw ScalarConverter::NonDisplayable();
			break;
		case FLOAT:
			c = static_cast<char>(ScalarConverter::_float_value);
			if (isnan(ScalarConverter::_float_value) || isinf(ScalarConverter::_float_value)
				|| ScalarConverter::_float_value > std::numeric_limits<char>::max()
				|| ScalarConverter::_float_value < std::numeric_limits<char>::min())
				throw ScalarConverter::Impossible();
			else if (!isprint(c))
				throw ScalarConverter::NonDisplayable();
			break;
		case DOUBLE:
			c = static_cast<char>(ScalarConverter::_double_value);
			if (isnan(ScalarConverter::_double_value) || isinf(ScalarConverter::_double_value)
				|| ScalarConverter::_double_value > std::numeric_limits<char>::max()
				|| ScalarConverter::_double_value < std::numeric_limits<char>::min())
				throw ScalarConverter::Impossible();
			else if (!isprint(c))
				throw ScalarConverter::NonDisplayable();
			break;
	}
	return (c);
}

int	ScalarConverter::toInt(void)
{
	int	n;

	switch(ScalarConverter::_type)
	{
		case CHARACTER:
			n = static_cast<int>(ScalarConverter::_char_value);
			break;
		case INTEGER:
			n = ScalarConverter::_int_value;
			break;
		case FLOAT:
			n = static_cast<int>(ScalarConverter::_float_value);
			if (isnan(ScalarConverter::_float_value) || isinf(ScalarConverter::_float_value)
				|| ScalarConverter::_float_value > std::numeric_limits<int>::max()
				|| ScalarConverter::_float_value < std::numeric_limits<int>::min())
				throw ScalarConverter::Impossible();
			break;
		case DOUBLE:
			n = static_cast<int>(ScalarConverter::_double_value);
			if (isnan(ScalarConverter::_double_value) || isinf(ScalarConverter::_double_value)
				|| ScalarConverter::_double_value > std::numeric_limits<int>::max()
				|| ScalarConverter::_double_value < std::numeric_limits<int>::min())
				throw ScalarConverter::Impossible();
			break;
	}
	return (n);
}

float ScalarConverter::toFloat(void)
{
	float f;

	switch(ScalarConverter::_type)
	{
		case CHARACTER:
			f = static_cast<float>(ScalarConverter::_char_value);
			break;
		case INTEGER:
			f = static_cast<float>(ScalarConverter::_int_value);
			break;
		case FLOAT:
			f = ScalarConverter::_float_value;
			break;
		case DOUBLE:
			f = static_cast<float>(ScalarConverter::_double_value);
			break;
	}
	return (f);
}

double ScalarConverter::toDouble(void)
{
	double d;

	switch(ScalarConverter::_type)
	{
		case CHARACTER:
			d = static_cast<double>(ScalarConverter::_char_value);
			break;
		case INTEGER:
			d = static_cast<double>(ScalarConverter::_int_value);
			break;
		case FLOAT:
			d = static_cast<double>(ScalarConverter::_float_value);
			break;
		case DOUBLE:
			d = ScalarConverter::_double_value;
			break;
	}
	return (d);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */