/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:05:06 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/06 00:24:58 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure()
	: AMateria("cure")
{
	std::cout << BGYELLOW << "Cure constructor called!" << RESET << std::endl;
}

Cure::Cure(const Cure &src)
	: AMateria(src)
{
	std::cout << BGYELLOW << "Cure copy constructor called!" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << BGYELLOW << "Cure copy destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	this->AMateria::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target) {
	std::cout << BGYELLOW << "* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */