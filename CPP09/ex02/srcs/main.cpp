/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:04:49 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/24 19:01:13 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc > 2)
	{
		try
		{
			PmergeMe a(argv + 1);
			// a.run();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error" << std::endl;
	return (0);
}