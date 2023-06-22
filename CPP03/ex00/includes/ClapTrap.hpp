/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:21:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/22 20:29:02 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
    private:
        std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		/*Orthodox Canonical Form*/
		ClapTrap(std::string _name_value);
		ClapTrap(const ClapTrap &original);
		ClapTrap& operator=(const ClapTrap &original);
		~ClapTrap();
		/*Member functions*/
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		/*Useful stuff*/
		void	printClapTrapInfo(void) const;
};

#endif
