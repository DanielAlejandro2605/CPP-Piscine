/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:23:41 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/28 16:54:12 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverterR_HPP
# define ScalarConverterR_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cerrno>
# include <ctype.h>
class ScalarConverter
{
	private:
		static char			_char_value;
		static int			_int_value;
		static float		_float_value;
		static double		_double_value;
		enum scalarType 	{CHARACTER, INTEGER, FLOAT, DOUBLE} _type;

		/*Orthodox Canonical Form*/
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);
		
		/*Methods*/
		static bool	IsPseudoLiteral(const std::string &arg);
		static bool	IsChar(const std::string	&arg);
		// static bool	IsInRange(long long int num);
	public:
		/*Methods*/
		static void	convert(const std::string	&arg);
		/*Accessors*/
		// std::string	getArg(void) const;
		
		/*Exceptions*/
		class InvalidInput : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("ScalarConverter: Invalid input!");
				}
		};
};

// std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************** ScalarConverter_H */