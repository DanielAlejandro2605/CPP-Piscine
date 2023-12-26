/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:18:01 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/23 11:16:11 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define PURPLE    "\e[95m"

#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

template <typename T>
class Array
{
	private:
		T*				_data;
    	unsigned int	_array_size;
	public:
		/*Construction without parameters*/
		Array();
		/*Construction with an unsigned int n as a parameter*/
		Array(unsigned int n);
		/*Copy constructor an operator '=' overload*/
		Array(Array const &src);
		Array &		operator=(Array const &rhs);
		/*Subscript operator*/
		T& operator[](size_t index);
		/*Member function size*/
		unsigned int size() const;
		/*Destructor*/
		~Array();

		class OutOfRangeException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Array: Index out of range");
			}
		};
};

#include "Array.tpp"

#endif /* *********************************************************** ARRAY_H */