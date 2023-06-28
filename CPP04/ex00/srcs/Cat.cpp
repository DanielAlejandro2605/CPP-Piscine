/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:32:33 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/28 23:37:29 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal("Cat")
{
	std::cout << BGCYAN << "Cat constructor called!" << RESET << std::endl;
	return ;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << BGCYAN << "Cat copy constructor called!" << RESET << std::endl;
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << BGCYAN << "Cat destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Cat &				Cat::operator=( Cat const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

std::ostream& operator<<(std::ostream &output, Cat const &instance_cat)
{
    output << CYAN << "******************************" RESET <<  std::endl;
	output << CYAN << "********   ANIMAL    *********" RESET <<  std::endl;
    output << BLUE << "| TYPE : " << instance_cat.getType() << RESET << std::endl;
	output << CYAN << "******************************" RESET <<  std::endl;
	return (output);
}
/*
** --------------------------------- METHODS ----------------------------------
*/
void	Cat::makeSound(void) const {
	std::cout << BGGREEN << "Cat : meow meow meow!" << RESET << std::endl;	
} 
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */