/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:54:42 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/29 20:24:25 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Dog::Dog() : Animal("Dog")
{
	std::cout << BGMAGENTA << "Dog constructor called!" << RESET << std::endl;
	return ;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << BGMAGENTA << "Dog copy constructor called!" << RESET << std::endl;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Dog::~Dog()
{
	std::cout << BGMAGENTA << "Dog destructor called!" << RESET << std::endl;
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &output, Dog const &instance_dog)
{
    output << CYAN << "******************************" RESET <<  std::endl;
	output << CYAN << "********   ANIMAL    *********" RESET <<  std::endl;
    output << BLUE << "| TYPE : " << instance_dog.getType() << RESET << std::endl;
	output << CYAN << "******************************" RESET <<  std::endl;
	return (output);
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void		Dog::makeSound(void) const {
	std::cout << BGGREEN << "Dog : bark bark bark!" << RESET << std::endl;	
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */