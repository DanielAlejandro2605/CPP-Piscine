/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:45:34 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/04 17:06:25 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("default_diamond_clap_name"), ScavTrap(), FragTrap(), _name("default_diamond")
{
	std::cout << BGMAGENTA << "DiamondTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name  + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << BGMAGENTA << "DiamondTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

// DiamondTrap::DiamondTrap() : ClapTrap("default_diamond_clap_name"), ScavTrap(), FragTrap(), _name("default_diamond")
// {
// 	std::cout << BGMAGENTA << "DiamondTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
//     this->_hit_points = FragTrap::_hit_points; // 100
//     this->_energy_points = ScavTrap::_energy_points; // 50
//     this->_attack_damage =FragTrap::_attack_damage; // 30
// }

// DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name  + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
// {
// 	std::cout << BGMAGENTA << "DiamondTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
//     this->_hit_points = FragTrap::_hit_points; // 100
//     this->_energy_points = ScavTrap::_energy_points; // 50
//     this->_attack_damage =FragTrap::_attack_damage; // 30
// }

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original), ScavTrap(), FragTrap() {
	std::cout << BGMAGENTA << "DiamondTrap inherited copy constructor from ClapTrap called!" << RESET << std::endl;
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

/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::attack(const std::string& target) {
    this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
    std::cout << MAGENTA << "Who I am ? " << RESET << std::endl;
    std::cout << MAGENTA << "Diamond name: " << this->_name << std::endl;
	std::cout << MAGENTA << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
}

/*Additional stuff*/
std::string	DiamondTrap::getClapTrapName(void) const {
    return (this->ClapTrap::getName());   
}

std::string	DiamondTrap::getName(void) const {
    return (this->_name);
}

/*
**

}-------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

std::ostream &operator<<( std::ostream &output, DiamondTrap const &instance_diamond_trap)
{
	output << CYAN << "******************************" << std::endl;
    output << BLUE << "|    CLAP TRAP NAME : " << instance_diamond_trap.getClapTrapName() << std::endl;
    output << BLUE << "|    NAME : " << instance_diamond_trap.getName() << std::endl;
    output << BLUE << "|    HIT POINTS : " << instance_diamond_trap.getHitPoints() << std::endl;
    output << BLUE << "|    ENERGY POINTS : " << instance_diamond_trap.getEnergyPoints() << std::endl;
    output << BLUE << "|    ATTACK DAMAGE : " << instance_diamond_trap.getAttackDamage() << std::endl;
    output << BLUE << "------------------------------" << std::endl;
	return (output);
}
