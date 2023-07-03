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

int main( void )
{
    {
		std::cout << "Testing Orthodox Canonical Form" << std::endl;
		ScavTrap	my_scavtrap("Daniel");
		std::cout << my_scavtrap;
		ScavTrap	my_scavtrap2("Alejandro");
		std::cout << my_scavtrap2;
		my_scavtrap2 = my_scavtrap;
		std::cout << my_scavtrap2;
		ScavTrap	my_scavtrap3;
		std::cout << my_scavtrap3;
    }

	{
		std::cout << "Testing only ScavTrap member functions" << std::endl;
		ScavTrap	my_scavtrap("Daniel");
		ScavTrap	my_scavtrap2("Alejandro");
		my_scavtrap.attack("Alejandro");
		my_scavtrap2.guardGate();
	}

	{
		std::cout << "Testing ScavTrap and ClapTrap" << std::endl;
		ScavTrap	my_scavtrap("Daniel");
		{
			std::cout << GREEN << "********** First fight! ********************" RESET <<  std::endl;
			ClapTrap	my_claptrap("Alejandro");
			my_scavtrap.attack("Alejandro");
			my_claptrap.takeDamage(my_scavtrap.getAttackDamage());
			my_claptrap.attack("Daniel");
			my_scavtrap.attack("Alejandro");
			my_claptrap.takeDamage(my_scavtrap.getAttackDamage());
		}
		{
			std::cout << GREEN << "********** Second fight! ********************" RESET <<  std::endl;
			ClapTrap	my_claptrap("Juan Pablo");
			my_claptrap.attack("Daniel");
			my_scavtrap.takeDamage(my_claptrap.getAttackDamage());
			my_scavtrap.attack("Juan Pablo");
			my_claptrap.takeDamage(my_scavtrap.getAttackDamage());
			my_claptrap.attack("Juan Pablo");
			my_scavtrap.attack("Daniel");
			my_claptrap.takeDamage(my_scavtrap.getAttackDamage());
		}
		{
			std::cout << GREEN << "********** Third fight! ********************" RESET <<  std::endl;
			ScavTrap	my_scavtrap2("Nicolas");
			my_scavtrap2.attack("Daniel");
			my_scavtrap.takeDamage(my_scavtrap2.getAttackDamage());
			my_scavtrap.attack("Nicolas");
			my_scavtrap2.takeDamage(my_scavtrap.getAttackDamage());
			my_scavtrap2.attack("Daniel");
			my_scavtrap.takeDamage(my_scavtrap2.getAttackDamage());
			my_scavtrap.attack("Nicolas");
			my_scavtrap2.takeDamage(my_scavtrap.getAttackDamage());
			my_scavtrap.guardGate();
			my_scavtrap.attack("Nicolas");
			my_scavtrap2.takeDamage(my_scavtrap.getAttackDamage());
			my_scavtrap.attack("Nicolas");
			my_scavtrap2.takeDamage(my_scavtrap.getAttackDamage());
			my_scavtrap.attack("Nicolas");
			my_scavtrap2.takeDamage(my_scavtrap.getAttackDamage());
		}
	}
    return 0;
}