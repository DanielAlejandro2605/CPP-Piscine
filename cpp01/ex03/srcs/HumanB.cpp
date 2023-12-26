/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:56:20 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 13:44:24 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name_value) : _name(name_value)
{
    this->_weapon_type = 0;
    std::cout << "Constructor of HumanB class!" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "Destructor of HumanB class!" << std::endl;
}

void    HumanB::setWeapon(Weapon &weap_type_class)
{
    this->_weapon_type = &weap_type_class;
}

void	HumanB::attack(void)
{
    std::cout << this->_name;
    std::cout << " attacks with their ";
    if (this->_weapon_type)
        std::cout << this->_weapon_type->getType();
    else
        std::cout << "attacks with his body and without a weapon";
    std::cout << std::endl;
}