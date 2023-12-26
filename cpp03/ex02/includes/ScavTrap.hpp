/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:32:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 16:40:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "../includes/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();
		/*Member functions*/
		void	attack(const std::string& target);
		void	guardGate(void);
};

std::ostream& operator<<(std::ostream &output, ScavTrap const &instance_scrav_trap);
#endif 