/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:09:51 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/04 13:09:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        Harl HarlRobot(argv[1]);
        HarlRobot.harlFilter();
    }
    return 0;
}
