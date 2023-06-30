/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:15:07 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/30 17:21:11 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"

int main(void)
{
    Character	first_character("Daniel");
	std::cout << first_character;
	Character	second_character(first_character);
	std::cout << second_character;
	first_character.printInventory();
	
	return (0);
}