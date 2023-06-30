/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:42:00 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 23:46:34 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
	: _type("WrongAnimal")
{
	std::cout << BGYELLOW << "WrongAnimal constructor called!" << RESET << std::endl;
	return;
}

WrongAnimal::WrongAnimal(std::string _type_animal)
	: _type(_type_animal)
{
	std::cout << BGYELLOW << "WrongAnimal constructor called!" << RESET << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << BGYELLOW << "WrongAnimal  copy constructor called!" << RESET << std::endl;
	this->_type.assign(src._type);
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << BGYELLOW << "WrongAnimal destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &output, WrongAnimal const &instance_wrong_animal)
{
	output << CYAN << "******************************" RESET <<  std::endl;
	output << CYAN << "********   ANIMAL    *********" RESET <<  std::endl;
    output << BLUE << "| TYPE : " << instance_wrong_animal.getType() << RESET << std::endl;
	output << CYAN << "******************************" RESET <<  std::endl;
	return (output);
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	WrongAnimal::makeSound(void) const {
	std::cout << BGGREEN << "WrongAnimal making a sound kokoko!" << RESET << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string	WrongAnimal::getType (void) const {
	return (this->_type);
}