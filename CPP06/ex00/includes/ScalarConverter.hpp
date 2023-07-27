/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:23:41 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/27 14:59:03 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverterR_HPP
# define ScalarConverterR_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	private:
		std::string	_arg;
		// char				_char_value;
		// int					_int_value;
		// float				_float_value;
		// double				_double_value;
	public:
		ScalarConverter(const std::string arg);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);
		/*Methods*/
		void		convert();
		/*Accessors*/
		std::string	getArg(void) const;
		
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