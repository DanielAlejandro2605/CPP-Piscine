/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:48:08 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/03 19:43:49 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*Orthodox Canonical Form*/
ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << BGYELLOW << "ScavTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << BGYELLOW << "ScavTrap inherited constructor from ClapTrap called!" << RESET << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original) {
    std::cout << BGYELLOW << "ScavTrap inherited copy constructor from ClapTrap called!" << RESET << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << BGYELLOW << "ScavTrap destructor called!" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
    if (this->_hit_points <= 0 || this->_energy_points <= 0)
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
