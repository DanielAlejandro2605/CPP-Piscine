/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:45:34 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 21:35:48 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("default_clapTrap_clap_name"), ScavTrap(), FragTrap(), name("default_clapTrap_clap_name")
{
	std::cout << BGMAGENTA << "DiamondTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(), FragTrap(), name(name + "_clap_name")
{
	std::cout << BGMAGENTA << "DiamondTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original), ScavTrap(), FragTrap() {
	std::cout << BGMAGENTA << "DiamondTrap inherited copy constructor from ClapTrap called!" << RESET << std::endl;	
    this->_name.assign(original._name);
    this->_hit_points = original._hit_points;
    this->_energy_points = original._energy_points;
    this->_attack_damage = original._attack_damage;
    this->name.assign(this->_name.append("_clap_name"));
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << BGMAGENTA << "DiamondTrap destructor called!" << RESET << std::endl;
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

std::ostream &operator<<( std::ostream &output, DiamondTrap const &instance_diamond_trap)
{
	output << CYAN << "******************************" << std::endl;
    output << BLUE << "|    NAME : " << instance_frag_trap.getName() << std::endl;
    output << BLUE << "|    HIT POINTS : " << instance_frag_trap.getHitPoints() << std::endl;
    output << BLUE << "|    ENERGY POINTS : " << instance_frag_trap.getEnergyPoints() << std::endl;
    output << BLUE << "|    ATTACK DAMAGE : " << instance_frag_trap.getAttackDamage() << std::endl;
    output << BLUE << "------------------------------" << std::endl;
	return (output);
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */