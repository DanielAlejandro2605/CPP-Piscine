/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:20:16 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/23 22:17:46 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/*Orthodox Canonical Form*/
ClapTrap::ClapTrap(std::string name_value)
    : _name(name_value), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << RED << "ClapTrap default constructor called!" RESET << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &original){
    std::cout << RED "ClapTrap copy constructor called!" RESET << std::endl;
    this->_name.assign(original._name);
    this->_hit_points = original._hit_points;
    this->_energy_points = original._energy_points;
    this->_attack_damage = original._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original){
    std::cout << RED "ClapTrap copy assignment operator called!" RESET << std::endl;
    if (this == &original)
        return (*this);
    this->_name.assign(original._name);
    this->_hit_points = original._hit_points;
    this->_energy_points = original._energy_points;
    this->_attack_damage = original._attack_damage;
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << RED << "ClapTrap destructor called!" RESET << std::endl;
    return ;
}

/*Member functions*/
void	ClapTrap::attack(const std::string& target){
    if (this->_hit_points == 0 || this->_energy_points == 0)
    {
        std::cout << PURPLE << "ClapTrap " << this->_name << " has no resources to attack." RESET << std::endl;
        return ;
    }
    this->_energy_points = this->_energy_points - 1;
    std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit_points == 0 || this->_energy_points == 0)
    {
        std::cout << PURPLE << "Stopping damage! ClapTrap " << this->_name << " is already died!" RESET << std::endl;
    }
    else if (amount > this->_hit_points)
    {
        std::cout << PURPLE << "ClapTrap " << this->_name << " takes damage of " << amount << " and dies!" RESET << std::endl;
        this->_hit_points = 0;
    }
    else
    {
        this->_hit_points = this->_hit_points - amount; 
        std::cout << YELLOW  << "ClapTrap " << this->_name << " takes damage of " << amount;
        if (this->_hit_points == 0)
            std::cout << " and dies!" RESET << std::endl;
        else
            std::cout << " remaining " << this->_hit_points << RESET << std::endl;  
    }
}

void	ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energy_points == 0)
    {
        std::cout << PURPLE << "ClapTrap " << this->_name << " has no energy resources to repairs itself." << std::endl;
        return ;
    }
    this->_hit_points = this->_hit_points + amount;
    std::cout << YELLOW << "ClapTrap " << this->_name << " gets " << amount << " hit points back." RESET << std::endl;
    std::cout << YELLOW << "ClapTrap " << this->_name << " remaining " << this->_hit_points << RESET << std::endl;  
}

/*Useful stuff*/
std::string		ClapTrap::getName(void) const {
    return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
    return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
    return (this->_energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
    return (this->_attack_damage);
}
        
std::ostream& operator<<(std::ostream &output, ClapTrap const &instance_clap_trap)
{
    output << CYAN << "******************************" RESET <<  std::endl;
    output << BLUE << "|    NAME : " << instance_clap_trap.getName() << RESET << std::endl;
    output << BLUE << "|    HIT POINTS : " << instance_clap_trap.getHitPoints() << RESET << std::endl;
    output << BLUE << "|    ENERGY POINTS : " << instance_clap_trap.getEnergyPoints() << RESET << std::endl;
    output << BLUE << "|    ATTACK DAMAGE : " << instance_clap_trap.getAttackDamage() << RESET << std::endl;
    output << CYAN << "------------------------------" << RESET << std::endl;
	return (output);
}