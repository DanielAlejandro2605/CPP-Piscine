/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:58:02 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/09/13 17:24:37 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RNP.hpp"

int main(int argc, char *argv[])
{
	(void)argc;
	try {
		if (!argv[1])
		{
			throw RNP::Error();
		}
		RNP rnp;
    	rnp.run(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}
