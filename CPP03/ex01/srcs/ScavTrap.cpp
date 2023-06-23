/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:48:08 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/23 21:29:02 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*Orthodox Canonical Form*/
ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
    std::cout << YELLOW << "ScavTrap inherited constructor from ClapTrap called!" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original) {
    std::cout << YELLOW << "ScavTrap inherited copy constructor from ClapTrap called!" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << YELLOW << "ScavTrap destructor called!" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
    if (this->_hit_points == 0 || this->_energy_points == 0)
    {
        std::cout << PURPLE << "ScavTrap " << this->_name << " has no resources to attack." RESET << std::endl;
        return ;
    }
    this->_energy_points = this->_energy_points - 1;
    std::cout << YELLOW << "ScavTrap " << this->_name << " attacks " << target << ",causing " << this->_attack_damage << " points of damage!" RESET << std::endl;
}

void	ScavTrap::guardGate(void) {
    if (this->_energy_points == 0)
    {
        std::cout << PURPLE << "ScavTrap " << this->_name << " has no energy resources to become the guardian of the gate." RESET << std::endl;
        return ;
    }
    std::cout << PURPLE << "ScavTrap " << this->_name << " is now the guardian of the gate." RESET << std::endl;
}

/*Useful stuff*/
std::string		ScavTrap::getName(void) const {
    return (this->_name);
}

unsigned int	ScavTrap::getHitPoints(void) const {
    return (this->_hit_points);
}

unsigned int	ScavTrap::getEnergyPoints(void) const {
    return (this->_energy_points);
}

unsigned int	ScavTrap::getAttackDamage(void) const {
    return (this->_attack_damage);
}

std::ostream& operator<<(std::ostream &output, ScavTrap const &instance_scrav_trap)
{
    output << CYAN << "******************************" << std::endl;
    output << BLUE << "|    NAME : " << instance_scrav_trap.getName() << std::endl;
    output << BLUE << "|    HIT POINTS : " << instance_scrav_trap.getHitPoints() << std::endl;
    output << BLUE << "|    ENERGY POINTS : " << instance_scrav_trap.getEnergyPoints() << std::endl;
    output << BLUE << "|    ATTACK DAMAGE : " << instance_scrav_trap.getAttackDamage() << std::endl;
    output << BLUE << "------------------------------" << std::endl;
	return (output);
}
