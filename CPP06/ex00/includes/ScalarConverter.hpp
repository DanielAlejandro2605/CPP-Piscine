/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:23:41 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/01 10:21:56 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverterR_HPP
# define ScalarConverterR_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <limits>
# include <cerrno>
# include <ctype.h>
# include <cmath>
# include <sstream>
class ScalarConverter
{
	private:
		static int				_type;
		static char				_char_value;
		static int				_int_value;
		static float			_float_value;
		static double			_double_value;
		enum 	_types {CHARACTER, INTEGER, FLOAT, DOUBLE, UNDEFINED, NUL};
		/*Orthodox Canonical Form*/
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);
		
		/*Methods*/
		static void		setType(const std::string	&arg);
		static bool		isInvalidLiteral(const std::string	&arg);
		static char		toChar(void);
		static int		toInt(void);
		static float	toFloat(void);
		static double	toDouble(void);
	public:
		/*Methods*/
		static void	convert(const std::string	&arg);
		/*Accessors*/
		
		/*Exceptions*/
		class InvalidInput : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("ScalarConverter: Invalid input!");
				}
		};
		class OverflowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("ScalarConverter : This literal expression causes an integer overflow.");
				}
		};
		class NonDisplayable : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Non displayable");
				}	
		};
		class Impossible : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("impossible");
				}
		};
};

// std::ostream &operator<<(std::ostream &o, ScalarConverter const &i);

#endif /* ************************************************** ScalarConverter_H */