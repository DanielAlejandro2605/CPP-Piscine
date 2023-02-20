/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:46:53 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/02/20 19:56:12 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(void)
{
    std::string	myString = "HI THIS IS BRAIN";
	std::string	*myStringPtr = &myString;
	std::string &myStringReference = myString;

	// Memory Address
	std::cout << &myString << "\n";
	std::cout << myStringPtr << "\n";
	std::cout << &myStringReference << "\n";

	// Values
	std::cout << myString << "\n";
	std::cout << *myStringPtr << "\n";
	std::cout << myStringReference << "\n";
	return (0);
}