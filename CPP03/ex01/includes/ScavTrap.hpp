/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:32:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/22 20:11:30 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "../includes/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &original);
		// ScavTrap& operator=(const ScavTrap &original);
		~ScavTrap();
		void	guardGate(void);
};
#endif 