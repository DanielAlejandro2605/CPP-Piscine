/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:14 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/23 14:49:14 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main( void )
{
    {
		std::cout << "Testing Orthodox Canonical Form" << std::endl;
		FragTrap	my_fragtrap("Daniel");
		ScavTrap	my_scavtrap;
		std::cout << my_fragtrap << std::endl;
		std::cout << my_scavtrap << std::endl;
		std::cout << GREEN << "********** Little fight! ********************" << RESET <<  std::endl;
		my_fragtrap.attack("ClapTrap default");
		my_scavtrap.takeDamage(my_fragtrap.getAttackDamage());
		my_scavtrap.attack("Daniel");
		my_fragtrap.takeDamage(my_scavtrap.getAttackDamage());
		my_scavtrap.attack("Daniel");
		my_fragtrap.takeDamage(my_scavtrap.getAttackDamage());
		my_fragtrap.attack("default ClapTrap");
		my_scavtrap.takeDamage(my_fragtrap.getAttackDamage());
		my_scavtrap.guardGate();
		my_fragtrap.highFivesGuys();
		my_scavtrap.takeDamage((my_fragtrap.getAttackDamage() * 3));
		my_scavtrap.attack("Daniel");
		my_scavtrap.beRepaired(10);
		std::cout << GREEN << "*********************************************" RESET <<  std::endl;
		std::cout << my_fragtrap;
		std::cout << my_scavtrap;
    }
    return 0;
}