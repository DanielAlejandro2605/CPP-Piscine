/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:56:26 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/21 19:07:15 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon()
{
    std::cout << "Constructor of Weapon class!\n";
}

Weapon::Weapon(std::string type_value)
{
    std::cout << "Constructor of Weapon class!\n";
	this->type.assign(type_value);
}

Weapon::~Weapon()
{
    std::cout << "Destructor of Weapon class!\n";
}

std::string	Weapon::getSimpleType(void)
{
	return (this->type);
}

const std::string&	Weapon::getType(void)
{
	const std::string &typeReference = this->type;
	return (typeReference);
}

void	Weapon::setType(std::string new_value_type)
{
	this->type = new_value_type;
}