/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:09:32 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 16:35:33 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
	: _type("Default animal")
{
	std:cout << BGRED << "Animal constructor called!" << std::endl;
	
}

Animal::Animal(std::string _type_animal)
	: _type(_type_animal) 
{
	std:cout << BGRED << "Animal constructor called!" << std::endl;
}


Animal::Animal(const Animal &src)
{
	std:cout << BGRED << "Animal copy constructor called!" << std::endl;
	this->_type.assign(src._type);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std:cout << BGRED << "Animal destructor called!" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if (this != &rhs)
	{
		this->_value = rhs.getType();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &output, Animal const &instance_animal)
{
    output << CYAN << "******************************" RESET <<  std::endl;
    output << BLUE << "| 	TYPE : " << instance_animal.getType() << RESET << std::endl;
	return (output);
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
std::string	getType(void) const {
	return (this->_type);
}