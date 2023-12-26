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

#include "../includes/ClapTrap.hpp"

int main( void )
{
    {
        std::cout << "Testing Orthodox Canonical Form" << std::endl;
        ClapTrap	first_clap_trap("Daniel");
		std::cout << first_clap_trap << std::endl;
		ClapTrap	second_clap_trap("Alejandro");
		std::cout << second_clap_trap << std::endl;
		second_clap_trap = first_clap_trap;
		std::cout << second_clap_trap << std::endl;
		ClapTrap third_clap_trap(second_clap_trap);
		std::cout << third_clap_trap << std::endl;
    }
	{
		std::cout << "**********************************************************" << std::endl;
		std::cout << "Testing member functions" << std::endl;
		ClapTrap	first_clap_trap("Daniel");
		std::cout << first_clap_trap << std::endl;
		first_clap_trap.attack("Chelo");
		first_clap_trap.attack("Miguel");
		first_clap_trap.attack("Alix");
		first_clap_trap.attack("Amanda");
		first_clap_trap.attack("Yoel");
		std::cout << first_clap_trap << std::endl;
		first_clap_trap.takeDamage(5416515);
		first_clap_trap.beRepaired(5);
		std::cout << first_clap_trap << std::endl;
	}
	{
		ClapTrap john("John");
		std::cout << john;
		ClapTrap jim("Jim");
		std::cout << jim;
		ClapTrap joe("Joe");
		std::cout << joe;
		john.attack("Marge");
		john.attack("Bart");
		john.attack("Homer");
		john.takeDamage(5);
		jim.takeDamage(9);
		jim.takeDamage(10);
		std::cout << joe << std::endl;
		joe.beRepaired(12);
		std::cout << joe << std::endl;
		joe.takeDamage(19);
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
		std::cout << joe << std::endl;
	}
	{
		ClapTrap john("John");
		for (int i = 0; i < 11; i++)
			john.attack("someone");
	}
    return 0;
}