/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:56:16 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/23 19:19:05 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"


HumanA::HumanA(std::string name_value, Weapon& weap_type_class) : _name(name_value), _weapon_type(weap_type_class)
{
    std::cout << "Constructor of HumanA class!\n";
}


HumanA::~HumanA()
{
    std::cout << "Destructor of HumanA class!\n";
}

void	HumanA::attack(void)
{
    std::cout << this->_name;
    std::cout << " attacks with their ";
    std::cout << this->_weapon_type.getType();
    std::cout << "\n";
}
