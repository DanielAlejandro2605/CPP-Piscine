/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:57:08 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/23 19:09:15 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

# include "../includes/Weapon.hpp"

class HumanA
{
    private:
		std::string	_name;
		Weapon&		_weapon_type;
	public:
		HumanA(std::string name_value, Weapon& weap_type_class);
		~HumanA();
		void	attack(void);
};

#endif