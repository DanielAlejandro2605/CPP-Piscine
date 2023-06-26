/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:56:02 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/03/01 16:56:02 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Executing the constructor of Harl class" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Executing the destructor of Harl class" << std::endl;
}

void	Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void    Harl::complain(std::string level)
{
	void		(Harl::*HarlFunctions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	harl_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (level.compare(harl_levels[i]) == 0)
		{
			(this->*HarlFunctions[i])();
		}
		i++;
	}
}
