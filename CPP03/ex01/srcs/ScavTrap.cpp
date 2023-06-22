/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:48:08 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/22 20:14:49 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
    std::cout << "Execution of the inherited constructor of the ScavTrap Class which uses the default constructor of ClapTrap Class" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original) {
    std::cout << "Execution of the inherited copy constructor of the ScavTrap Class which uses the default constructor of ClapTrap Class!" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "Execution of the destructor of the ScavTrap Class which uses the default destructor of ClapTrap Class!\n";
}