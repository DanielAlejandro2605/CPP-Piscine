/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:30:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/29 19:36:04 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(std::string const &type)
	: _type(type)
{
	std::cout << GREEN << "AMateria constructor called!" << RESET << std::endl;
	return ;
}

AMateria::AMateria(const AMateria &src)
	: _type(src._type)
{
	std::cout << GREEN << "AMateria copy constructor called!" << RESET << std::endl;
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << GREEN << "AMateria destructor called!" << RESET << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria&	AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const &AMateria::getType(void) const {
	return (this->_type);	
}

void	AMateria::use(ICharacter &target) {
	(void)target;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */