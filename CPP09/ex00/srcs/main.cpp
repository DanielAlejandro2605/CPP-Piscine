/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:12:35 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/08/18 11:57:42 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	(void)argc;
	try {
		if (!argv[1])
			throw BitcoinExchange::ErrorOpenArgFile();
		BitcoinExchange btc;
		btc.exchange(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return (0);
}
