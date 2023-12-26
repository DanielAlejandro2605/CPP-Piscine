/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:54:42 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/29 23:34:26 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Dog::Dog() : Animal("Dog")
{
	std::cout << BGMAGENTA << "Dog constructor called!" << RESET << std::endl;
	this->_brain = new Brain();
	return ;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << BGMAGENTA << "Dog copy constructor called!" << RESET << std::endl;
	*this = src;
	return ;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Dog::~Dog()
{
	delete this->_brain;
	std::cout << BGMAGENTA << "Dog destructor called!" << RESET << std::endl;
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		if (this->_brain)
			delete this->_brain;
		this->_type = rhs.getType();
		this->_brain = new Brain(*rhs._brain);
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

Brain*		Dog::getBrain(void) const {
	return (this->_brain);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */