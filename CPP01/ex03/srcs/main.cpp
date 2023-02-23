/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:56:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/23 19:29:24 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "../includes/Weapon.hpp"

# include "../includes/HumanA.hpp"
# include "../includes/HumanB.hpp"

int main(void)
{
    {
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "\n\n";
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		// jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.setWeapon(club);
		jim.attack();
	}
	return (0);
}