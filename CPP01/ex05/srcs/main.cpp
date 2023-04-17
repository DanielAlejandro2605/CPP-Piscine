/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:26:01 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/03 16:26:01 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(void)
{
    Harl HarlRobot;

    std::cout << "What do you want today Harl?\n";
    HarlRobot.complain("DEBUG");
    std::cout << "The extra bacon cost more money.\n";
    HarlRobot.complain("INFO");
	std::cout << "I'm sorry, those are the rules\n";
	HarlRobot.complain("WARNING");
	std::cout << "I can't help you\n";
	HarlRobot.complain("ERROR");
	std::cout << "I'm also the manager\n";
    return 0;
}
