/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:20:16 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 14:53:59 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/*Orthodox Canonical Form*/

ClapTrap::ClapTrap()
    : name("ClapTrap default name"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << BGWHITE "Constructor ClapTrap Class called!" << RESET << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string _name_value)
    : name(_name_value), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << BGWHITE "Constructor ClapTrap Class called!" << RESET << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &original){
    std::cout << "Execution of the copy constructor of the ClapTrap Class!\n";
    this->name.assign(original.name);
    this->hit_points = original.hit_points;
    this->energy_points = original.energy_points;
    this->attack_damage = original.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original){
    std::cout << "Execution of the copy assignment operator of the ClapTrap Class!\n";
    if (this == &original)
        return (*this);
    this->name.assign(original.name);
    this->hit_points = original.hit_points;
    this->energy_points = original.energy_points;
    this->attack_damage = original.attack_damage;
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "Execution of the destructor of the ClapTrap Class!\n";
    return ;
}

/*Member functions*/
void	ClapTrap::attack(const std::string& target){
    if (this->hit_points == 0 || this->energy_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " has no resources to attack." << std::endl;
        return ;
    }
    this->energy_points = this->energy_points - 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ",causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
    if (this->hit_points == 0 || this->energy_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " has is already died!" << std::endl;
    }
    else if (amount > this->hit_points)
    {
        std::cout << "ClapTrap " << this->name << " takes damage of " << amount << " and dies!" << std::endl;
    }
    else
    {
        this->hit_points = this->hit_points - amount; 
        std::cout << "ClapTrap " << this->name << " takes damage of " << amount << std::endl;
        std::cout << "ClapTrap " << this->name << " remaining " << this->hit_points << std::endl;  
    }
}

void	ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy resources to repairs itself." << std::endl;
        return ;
    }
    this->hit_points = this->hit_points + amount;
    std::cout << "ClapTrap " << this->name << " gets " << amount << " hit points back." << std::endl;
    std::cout << "ClapTrap " << this->name << " remaining " << this->hit_points << std::endl;  
}

/*Useful stuff*/
void	ClapTrap::printClapTrapInfo(void) const {
    std::cout << "**********************************************************" << std::endl;
    std::cout << "NAME : " << this->name << std::endl;
    std::cout << "HIT POINTS : " << this->hit_points << std::endl;
    std::cout << "ENERGY POINTS : " << this->energy_points << std::endl;
    std::cout << "ATTACK DAMAGE : " << this->attack_damage << std::endl;
}