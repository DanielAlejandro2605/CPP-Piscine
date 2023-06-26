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

Harl::Harl(const char *arg)
{
    std::cout << "Executing the constructor of Harl class" << std::endl;
	std::string	harl_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;
	this->_filter_level.assign(arg);

	i = 0;
	while (i < 4)
	{
		if (this->_filter_level.compare(harl_levels[i]) == 0)
			break;
		i++;
	}
	this->_level = i;
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

void    Harl::complain(int begin_level)
{
	void		(Harl::*HarlFunctions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	harl_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	i = begin_level;
	while (i < 4)
	{
		std::cout << "[ " << harl_levels[i] << "]" << std::endl;
		(this->*HarlFunctions[i])();
		std::cout << "" << std::endl;
		i++;
	}
}

void	Harl::harlFilter(void)
{
	switch (this->_level)
	{
		case 0:
			Harl::complain(0);
		break;
		case 1:
			Harl::complain(1);
		break;
		case 2:
			Harl::complain(2);
		break;
		case 3:
			Harl::complain(3);
		break;
	default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
