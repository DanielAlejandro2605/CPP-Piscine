/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:56:26 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/01 14:53:00 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon()
{
    std::cout << "Constructor of Weapon class without setting type member attribute!\n";
}

Weapon::Weapon(std::string type_value)
{
    std::cout << "Constructor of Weapon class and setting type member attribute!\n";
	this->setType(type_value);
}

Weapon::~Weapon()
{
    std::cout << "Destructor of Weapon class!\n";
}

const std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(const std::string new_value_type)
{
	this->_type = new_value_type;
}
