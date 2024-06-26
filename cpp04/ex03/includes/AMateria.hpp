/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:32:21 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/06 00:42:06 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "Character.hpp"
// Colores de texto
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

// Colores de fondo
#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

class ICharacter; // Why ?

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria();
		/*Operators*/
		AMateria &operator=(AMateria const &rhs);
		/*Methods*/
		virtual AMateria*	clone(void) const = 0;
		virtual void use(ICharacter &target) = 0;
		/*Useful stuff*/
		std::string const &getType(void) const;
};

#endif /* ******************************************************** AMATERIA_H */