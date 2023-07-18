/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:26:31 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/05 17:40:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
MateriaSource::MateriaSource()
{
	std::cout << BGWHITE << "MateriaSource constructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << BGWHITE << "MateriaSource copy constructor called!" << RESET << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
	std::cout << BGWHITE << "MateriaSource destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &MateriaSource::operator=( MateriaSource const & rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (rhs._materia[i])
			{
				delete rhs._materia[i];	
			}
			this->_materia[i] = rhs._materia[i] ? rhs._materia[i]->clone() : NULL;
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void MateriaSource::learnMateria(AMateria*m) {
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i] == NULL)
			{
				this->_materia[i] = m;
				std::cout << GREEN << "Learned Materia succesfully!" << RESET << std::endl; 
				return ;
			}
		}
		std::cout << RED << "MateriaSource slots are full!" << RESET << std::endl;
		delete m;
		return ;
	}
	std::cout << RED << "Cannot equip NULL Materias!" << RESET << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	
	for (int i = 0; i < 4; i++){
		if (this->_materia[i] && this->_materia[i]->getType() == type){
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */