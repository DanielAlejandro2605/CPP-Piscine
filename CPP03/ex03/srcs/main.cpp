/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:43:16 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 20:43:16 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main (void)
{
    {
        DiamondTrap diamond1("Daniel");
        DiamondTrap diamond2(diamond1);

        std::cout << diamond1;
        std::cout << diamond2;
        diamond1.whoAmI();
        diamond2.attack("Daniel");
    }
}