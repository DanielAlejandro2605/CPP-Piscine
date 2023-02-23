/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:56:42 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/20 18:56:42 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
	int		amt_zombies = 5;
	Zombie	*myZombieHorde = zombieHorde(amt_zombies, "Norminette");

	for (int i = 0;i < amt_zombies;i++)
		myZombieHorde[i].announce();

	delete [] myZombieHorde;
    return(0);
}