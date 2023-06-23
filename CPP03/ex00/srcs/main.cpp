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
		first_clap_trap.takeDamage(5);
		first_clap_trap.attack("Gabo");
		first_clap_trap.attack("Pieri");
		first_clap_trap.attack("Jean");
		first_clap_trap.attack("Romeo");
		std::cout << first_clap_trap << std::endl;
		first_clap_trap.beRepaired(2);
		first_clap_trap.attack("Alix");
		first_clap_trap.attack("Amanda");
	}
	{
		ClapTrap john("John");
		std::cout << john << std::endl;
		ClapTrap jim("Jim");
		std::cout << jim << std::endl;
		ClapTrap joe("Joe");
		std::cout << joe << std::endl;
		std::cout << RESET << std::endl;
		john.attack("Marge");
		john.attack("Bart");
		john.attack("Homer");
		john.takeDamage(5);
		jim.takeDamage(9);
		jim.takeDamage(10);
		joe.beRepaired(10);
		joe.takeDamage(19);
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
		std::cout << joe << std::endl;
	}
    return 0;
}