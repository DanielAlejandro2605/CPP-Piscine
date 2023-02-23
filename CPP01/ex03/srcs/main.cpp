/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:56:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/21 19:10:50 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Weapon.hpp"

int main(void)
{
    Weapon club = Weapon("crude spiked club");
    const std::string &type_of_club = club.getType();
    std::cout << type_of_club << "\n";
    return (0);
}