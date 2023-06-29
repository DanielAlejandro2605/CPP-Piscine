/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:30:58 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/29 19:34:04 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string _name)
	:	_name(_name)
{
	std::cout << CYAN << "Character constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &src)
{
	std::cout << CYAN << "Character copy constructor called!" << RESET << std::endl;
	// this->_name.assign(src._name);
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this->_inventory[i] != NULL)
	// 		delete this->_inventory[i];
	// 	this->_inventory[i] = src._inventory[i] ? src._inventory->clone() : NULL;
	// }
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << CYAN << "Character destructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	std::cout << CYAN << "Character operator overload called!" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name.assign(rhs._name);
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Character const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */