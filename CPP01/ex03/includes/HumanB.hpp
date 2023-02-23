/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:57:13 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/23 19:30:38 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

# include "../includes/Weapon.hpp"

class HumanB
{
    private:
		std::string _name;
        Weapon*		_weapon_type;
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &weap_type_class);
		void	attack(void);
};

#endif