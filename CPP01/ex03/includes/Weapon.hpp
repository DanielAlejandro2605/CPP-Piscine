/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:57:16 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/21 19:07:54 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

# include <iostream>

class Weapon
{
    private:
        std::string	type;
    public:
        Weapon();
		Weapon(std::string type_value);
        ~Weapon();
		std::string			getSimpleType(void);
        const std::string	&getType(void);
		void				setType(std::string new_value_type);
};

#endif 