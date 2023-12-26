/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:40:32 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 13:45:33 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		Sed mySed = Sed(argv + 1);
		mySed.sedIsForLosers();
	}
    else 
    {
		std::cout << "The sed program must have 2 arguments, no more no less" << std::endl;
    }
}