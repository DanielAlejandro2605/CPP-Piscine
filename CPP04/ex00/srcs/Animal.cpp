/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:09:32 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 23:45:14 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
	: _type("Animal")
{
	std::cout << BGRED << "Animal constructor called!" << RESET << std::endl;
	return ;
}

Animal::Animal(std::string _type_animal)
	: _type(_type_animal) 
{
	std::cout << BGRED << "Animal constructor called!" << RESET << std::endl;
	return ;
}


Animal::Animal(const Animal &src)
{
	std::cout << BGRED << "Animal copy constructor called!" << RESET << std::endl;
	this->_type.assign(src._type);
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << BGRED << "Animal destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &output, Animal const &instance_animal)
{
    output << CYAN << "******************************" RESET <<  std::endl;
	output << CYAN << "********   ANIMAL    *********" RESET <<  std::endl;
    output << BLUE << "| TYPE : " << instance_animal.getType() << RESET << std::endl;
	output << CYAN << "******************************" RESET <<  std::endl;
	return (output);
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	Animal::makeSound(void) const {
	std::cout << BGGREEN << "Animal making a sound yuoo!" << RESET << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string	Animal::getType (void) const {
	return (this->_type);
}