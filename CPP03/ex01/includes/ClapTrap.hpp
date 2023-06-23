/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:21:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/23 20:29:43 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
# define RED	"\e[91m"
# define GREEN	"\e[92m"
# define YELLOW	"\e[93m"
# define BLUE	"\e[94m"
# define PURPLE	"\e[95m"
# define CYAN	"\e[96m"
# define RESET	"\e[0m"

class ClapTrap {
    protected:
        std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	public:
		/*Orthodox Canonical Form*/
		ClapTrap(std::string name_value);
		ClapTrap(const ClapTrap &original);
		ClapTrap& operator=(const ClapTrap &original);
		~ClapTrap();
		/*Member functions*/
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		/*Useful stuff*/
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
};

/*Useful stuff*/
std::ostream& operator<<(std::ostream &output, ClapTrap const &fixed_point_number);
#endif
