/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:32:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/23 21:23:52 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "../includes/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();
		/*Member functions*/
		void	attack(const std::string& target);
		void	guardGate(void);
		/*Useful stuff*/
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
};

std::ostream& operator<<(std::ostream &output, ScavTrap const &instance_scrav_trap);
#endif 