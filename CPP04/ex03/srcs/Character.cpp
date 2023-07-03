/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:30:58 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/03 12:37:39 by dnieto-c         ###   ########.fr       */
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
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		else
		{
			std::cout << "Here" << std::endl;
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &Character::operator=( Character const & rhs )
{
	if (this != &rhs)
	{
		this->_name.assign(rhs._name);
		for (int i = 0; i < 4; i++)
		{
			if (rhs._inventory[i])
			{
				delete rhs._inventory[i];	
			}
			this->_inventory[i] = rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream &output, Character const &instance_character) {
	output << CYAN << "******************************" RESET <<  std::endl;
	output << CYAN << "********  Character  *********" RESET <<  std::endl;
    output << BLUE << "| NAME : " << instance_character.getName() << RESET << std::endl;
	output << CYAN << "******************************" RESET <<  std::endl;
	return (output);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = m;
				return ;
			}
		}
		std::cout << RED << "They equip Materias of " << this->_name << " is full!" << RESET << std::endl;
		delete m;
		return ; 
	}
	std::cout << RED << "Cannot equip NULL Materias!" << RESET << std::endl;
	return ;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
	{
		std::cout << GREEN << "Unequip " << this->_inventory[idx]->getType() << " Materia of " << this->_name << "!" << RESET << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << RED << "REMAIN: Equip of " << this->_name << " has only 4 slots!" << RESET << std::endl; 
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3)
	{
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
		else
			std::cout << RED << this->_name << ": Not Materia at the slot # " << idx << "!" << RESET << std::endl;
	}
	else
		std::cout << RED << "REMAIN: Equip of " << this->_name << " has only 4 slots!" << RESET << std::endl; 
}

void	Character::printInventory(void) const {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			std::cout << YELLOW << " [" << i << "]" << " : " << this->_inventory[i]->getType() << RESET << std::endl;
		else
			std::cout << YELLOW << " [" << i << "]" << " : Empty" << RESET << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */