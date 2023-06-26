/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:21:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 14:53:12 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

// Colores de texto
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

// Colores de fondo
#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"

class ClapTrap {
    private:
        std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		/*Orthodox Canonical Form*/
		ClapTrap();
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

// std::ostream&	operator<<(std::ostream &output, ClapTrap const &fixed_point_number)
// {
// 	output << fixed_point_number.toFloat();
// 	return (output);std::cout <<
// }
#endif
