/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:35:40 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/03 16:25:32 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/*Orthodox Canonical Form*/
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap() {
    std::cout << BGBLUE << "FragTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << BGBLUE << "FragTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original) {
	std::cout << BGBLUE << "FragTrap inherited copy constructor from ClapTrap called!" << RESET << std::endl;	
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << BGBLUE << "FragTrap destructor called!" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
std::ostream &			operator<<(std::ostream &output, FragTrap const &instance_frag_trap)
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
void	FragTrap::highFivesGuys(void){
    std::cout << "highFivesGuys power from FlagTrap" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */