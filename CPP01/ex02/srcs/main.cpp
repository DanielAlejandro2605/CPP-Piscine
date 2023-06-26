/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:46:53 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/26 13:43:35 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(void)
{
    std::string	myString = "HI THIS IS BRAIN";
	std::string	*myStringPtr = &myString;
	std::string &myStringReference = myString;

	// Memory Address
	std::cout << &myString << std::endl;
	std::cout << myStringPtr << std::endl;
	std::cout << &myStringReference << std::endl;

	// Values
	std::cout << myString << std::endl;
	std::cout << *myStringPtr << std::endl;
	std::cout << myStringReference << std::endl;
	return (0);
}