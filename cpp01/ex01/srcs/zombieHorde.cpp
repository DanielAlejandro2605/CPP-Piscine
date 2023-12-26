/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:56:33 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/20 19:24:22 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
    Zombie  *hordeZombies = new Zombie[N];
    for (int i = 0; i < N; i++)
        hordeZombies[i].setZombieName(name);
    return (hordeZombies);
}