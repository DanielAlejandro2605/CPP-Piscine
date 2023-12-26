/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:04:49 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/13 17:20:48 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		try
		{
			PmergeMe a(argv + 1);
			a.sort();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}