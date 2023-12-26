/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:56:39 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/20 18:56:39 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Now, executing the constructor of some Zombie class" << std::endl; 
}

Zombie::~Zombie()
{
    std::cout << "Now, executing the destructor of " << this->_name << std::endl;
}

void    Zombie::announce(void)
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setZombieName(std::string name_value)
{
    this->_name.assign(name_value);
}
