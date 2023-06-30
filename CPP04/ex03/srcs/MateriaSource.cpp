/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:26:31 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/30 17:56:59 by dnieto-c         ###   ########.fr       */
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
	std::cout << BGWHITE << "MateriaSource destructor called!" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
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

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i )
{
	//o << "Value = " << i.getValue();
	return o;
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
				return ;
			}
		}
		std::cout << BGWHITE << "Learned Materia succesfully!erias of " << this->_name << " is full!" << RESET << std::endl; 
	}
	std::cout << RED << "Cannot equip NULL Materias!" << RESET << std::endl;
	return ;
}

virtual AMateria* createMateria(std::string const & type) = 0;
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */