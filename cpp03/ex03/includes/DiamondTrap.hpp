/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:39:45 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/03 16:39:47 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &original);
		~DiamondTrap();
		// DiamondTrap &operator=( DiamondTrap const &original);
		void	whoAmI(void);
		void	attack(const std::string& target);
		/*Additional stuff*/
		std::string	getClapTrapName(void) const;
		std::string	getName(void) const;
};

std::ostream &operator<<( std::ostream &output, DiamondTrap const &instance_diamond_trap);

#endif /* ***************************************************** DIAMONDTRAP_H */
